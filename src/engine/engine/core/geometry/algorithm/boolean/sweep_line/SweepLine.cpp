#include "SweepLine.h"

#include <algorithm>

#include "../../../util/math.h"

zong::SweepLine::SweepLine(std::vector<zong::SegmentF>& segmentVec)
{
    resetSegmentsPoints(segmentVec);

    for (auto& segment : segmentVec)
    {
        PointEvent startPointEvent(segment.first(), EventType::StartPoint);
        PointEvent endPointEvent(segment.second(), EventType::EndPoint);
        startPointEvent.setOtherEvent(std::make_shared<PointEvent>(endPointEvent));
        endPointEvent.setOtherEvent(std::make_shared<PointEvent>(startPointEvent));
        _pointQueue.emplace(startPointEvent);
        _pointQueue.emplace(endPointEvent);

        // 加入端点
        _allCrossPoints.emplace(segment.first());
        _allCrossPoints.emplace(segment.second());
    }
}

// 对换点，保证第一个点是起始点，第二个点是终点
void zong::SweepLine::resetSegmentsPoints(std::vector<zong::SegmentF>& segments) const
{
    zong::PointF startPoint2d, endPoint2d;
    for (auto& segment : segments)
    {
        if (segment.first().x() < segment.second().x())
        {
            startPoint2d = segment.first();
            endPoint2d   = segment.second();
        }
        else if (segment.first().x() == segment.second().x())
        {
            if (segment.first().y() < segment.second().y())
            {
                startPoint2d = segment.first();
                endPoint2d   = segment.second();
            }
            else
            {
                startPoint2d = segment.second();
                endPoint2d   = segment.first();
            }
        }
        else
        {
            startPoint2d = segment.second();
            endPoint2d   = segment.first();
        }

        segment.first()  = startPoint2d;
        segment.second() = endPoint2d;
    }
}

void zong::SweepLine::updateSegmentTree(const double sweepLineXPos, const double sweepLineYPos)
{
    for (auto it = _segmentTree.begin(); it != _segmentTree.end(); ++it)
    {
        // 不用 const_cast 就改不了 SegmentEvent 的数据
        (const_cast<SegmentEvent&>(*it)).updateSweepLineCrossPoint(sweepLineXPos, sweepLineYPos);
    }
}

void zong::SweepLine::emplaceCrossPoint(int& a, int& b)
{
    std::vector<zong::PointF> crossPoints =
        _segmentTree[a].segment().intersection(_segmentTree[b].segment(), zong::util::HIGH_EPS_DOUBLE);

    if (crossPoints.empty())
        return;

    // 排序至与 m_priorityQueue 同序
    if (crossPoints.size() == 2)
    {
        zong::PointF tmpPoint = crossPoints[0];
        if (!IS_FLOAT_EQUAL(crossPoints[0].x(), crossPoints[1].x()))
        {
            if (crossPoints[0].x() > crossPoints[1].x())
            {
                crossPoints[0] = crossPoints[1];
                crossPoints[1] = tmpPoint;
            }
        }
        else
        {
            if (crossPoints[0].y() > crossPoints[1].y())
            {
                crossPoints[0] = crossPoints[1];
                crossPoints[1] = tmpPoint;
            }
        }
    }

    // 取数据
    zong::PointF crossPoint       = crossPoints[0];                   // 交点
    SegmentEvent        segmentA         = _segmentTree[a];                  // 线段 a
    PointEvent          aStartPointEvent = segmentA.startPointEvent();       // 从线段 a 裁剪出的线段的起点（会变）
    PointEvent          aEndPointEvent   = *(aStartPointEvent.otherEvent()); // 线段 a 的终点（不变）
    SegmentEvent        segmentB         = _segmentTree[b];                  // 线段 b
    PointEvent          bStartPointEvent = segmentB.startPointEvent();       // 从线段 b 裁剪出的线段的起点（会变）
    PointEvent          bEndPointEvent   = *(bStartPointEvent.otherEvent()); // 线段 b 的终点（不变）
    bool                isEndPointA;                                         // 是不是 a 的端点
    bool                isEndPointB;                                         // 是不是 b 的端点

    // 裁剪线段
    for (int i = 0; i < (int)crossPoints.size(); ++i)
    {
        isEndPointA = true;
        isEndPointB = true;

        crossPoint = crossPoints[i];
        PointEvent crossPointEvent(crossPoint, EventType::EndPoint);

        // 不是 a 的起点或终点
        if ((!IS_FLOAT_EQUAL(crossPoint.x(), segmentA.segment().first().x()) ||
             !IS_FLOAT_EQUAL(crossPoint.y(), segmentA.segment().first().y())) &&
            (!IS_FLOAT_EQUAL(crossPoint.x(), segmentA.segment().second().x()) ||
             !IS_FLOAT_EQUAL(crossPoint.y(), segmentA.segment().second().y())))
        {
            isEndPointA = false;

            aStartPointEvent.setEventType(EventType::StartPoint);
            aStartPointEvent.setOtherEvent(std::make_shared<PointEvent>(crossPointEvent));
            crossPointEvent.setOtherEvent(std::make_shared<PointEvent>(aStartPointEvent));

            // 只有第二个交点需要加起始点
            if (i == 1)
                _pointQueue.emplace(aStartPointEvent);
            _pointQueue.emplace(crossPointEvent);

            // 只有第一个交点需要裁剪线段
            if (i == 0)
            {
                _segmentTree[a].setStartPointEvent(aStartPointEvent);
                _segmentTree[a].setSegmentSecond(crossPointEvent.point());
            }

            // 更新 startPointEvent
            aStartPointEvent = crossPointEvent;
        }

        // 不是 b 的起点或终点
        if ((!IS_FLOAT_EQUAL(crossPoint.x(), segmentB.segment().first().x()) ||
             !IS_FLOAT_EQUAL(crossPoint.y(), segmentB.segment().first().y())) &&
            (!IS_FLOAT_EQUAL(crossPoint.x(), segmentB.segment().second().x()) ||
             !IS_FLOAT_EQUAL(crossPoint.y(), segmentB.segment().second().y())))
        {
            isEndPointB = false;

            bStartPointEvent.setEventType(EventType::StartPoint);
            bStartPointEvent.setOtherEvent(std::make_shared<PointEvent>(crossPointEvent));
            crossPointEvent.setOtherEvent(std::make_shared<PointEvent>(bStartPointEvent));

            // 只有第二个交点需要加起始点
            if (i == 1)
                _pointQueue.emplace(bStartPointEvent);
            _pointQueue.emplace(crossPointEvent);

            // 只有第一个交点需要裁剪线段
            if (i == 0)
            {
                _segmentTree[b].setStartPointEvent(bStartPointEvent);
                _segmentTree[b].setSegmentSecond(crossPointEvent.point());
            }

            // 更新 startPointEvent
            bStartPointEvent = crossPointEvent;
        }

        // 不是端点再加
        if (!isEndPointA && !isEndPointB)
        {
            _allCrossPoints.emplace(crossPoint);
        }
    }

    // 添加最后一段
    {
        // 不是 a 的起点或终点
        if ((!IS_FLOAT_EQUAL(crossPoint.x(), segmentA.segment().first().x()) ||
             !IS_FLOAT_EQUAL(crossPoint.y(), segmentA.segment().first().y())) &&
            (!IS_FLOAT_EQUAL(crossPoint.x(), segmentA.segment().second().x()) ||
             !IS_FLOAT_EQUAL(crossPoint.y(), segmentA.segment().second().y())))
        {
            aStartPointEvent.setOtherEvent(std::make_shared<PointEvent>(aEndPointEvent));
            aStartPointEvent.setEventType(EventType::StartPoint);
            aEndPointEvent.setOtherEvent(std::make_shared<PointEvent>(aStartPointEvent));
            _pointQueue.emplace(aStartPointEvent);
            _pointQueue.emplace(aEndPointEvent);
        }

        // 不是 b 的起点或终点
        if ((!IS_FLOAT_EQUAL(crossPoint.x(), segmentB.segment().first().x()) ||
             !IS_FLOAT_EQUAL(crossPoint.y(), segmentB.segment().first().y())) &&
            (!IS_FLOAT_EQUAL(crossPoint.x(), segmentB.segment().second().x()) ||
             !IS_FLOAT_EQUAL(crossPoint.y(), segmentB.segment().second().y())))
        {
            bStartPointEvent.setOtherEvent(std::make_shared<PointEvent>(bEndPointEvent));
            bStartPointEvent.setEventType(EventType::StartPoint);
            bEndPointEvent.setOtherEvent(std::make_shared<PointEvent>(bStartPointEvent));
            _pointQueue.emplace(bStartPointEvent);
            _pointQueue.emplace(bEndPointEvent);
        }
    }
}

void zong::SweepLine::scan()
{
    while (!_pointQueue.empty())
    {
        PointEvent pointEvent = _pointQueue.top();
        _pointQueue.pop();

        // 更新所有线段的排序标准
        double sweepLineXPos = pointEvent.point().x();
        updateSegmentTree(sweepLineXPos, pointEvent.point().y());

        // 点类型
        if (pointEvent.eventType() == EventType::StartPoint)
        {
            // 起点
            // 加入线段，并与其左右两条判交

            SegmentEvent tmpSegment2d(pointEvent, *(pointEvent.otherEvent()));
            _segmentTree.emplace_back(tmpSegment2d);

            std::sort(_segmentTree.begin(), _segmentTree.end(), [](SegmentEvent& a, SegmentEvent& b) -> bool {
                // SweepLineCrossPoint.x 肯定一样
                if (!IS_FLOAT_EQUAL(a.sweepLineCrossPoint().y(), b.sweepLineCrossPoint().y()))
                    return a.sweepLineCrossPoint().y() < b.sweepLineCrossPoint().y();
                else if (!IS_FLOAT_EQUAL(a.segment().second().y(), b.segment().second().y()))
                    return a.segment().second().y() < b.segment().second().y();
                else
                    return a.segment().second().x() < b.segment().second().x();
            });

            // 查找线段位置
            int it;
            for (int i = 0; i < (int)_segmentTree.size(); i++)
            {
                if (tmpSegment2d == _segmentTree[i])
                {
                    it = i;
                    break;
                }
            }
            auto prevIt = it - 1;
            auto nextIt = it + 1;

            // nextIt 存在
            if (nextIt != (int)_segmentTree.size())
                emplaceCrossPoint(it, nextIt);
            // prevIt 存在
            if (prevIt != -1)
                emplaceCrossPoint(it, prevIt);
        }
        else
        {
            // 终点
            // 线段左右判交，并删除线段

            SegmentEvent tmpSegment2d(pointEvent, *pointEvent.otherEvent());

            int it;

            // 如果能找到
            int i;
            for (i = 0; i < (int)_segmentTree.size(); i++)
            {
                if (tmpSegment2d == _segmentTree[i])
                {
                    it = i;
                    break;
                }
            }
            if (i == (int)_segmentTree.size())
                continue;

            auto prevIt = it - 1;
            auto nextIt = it + 1;

            // prevIt 和 nextIt 存在
            if (prevIt != -1 && nextIt != (int)_segmentTree.size())
                emplaceCrossPoint(prevIt, nextIt);

            _segmentTree.erase(_segmentTree.begin() + it);
        }
    }
}
