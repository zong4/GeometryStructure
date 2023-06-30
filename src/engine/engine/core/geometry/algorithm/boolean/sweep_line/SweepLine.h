#pragma once

#include <iterator>
#include <map>
#include <queue>
#include <set>

#include "../boolean_pch.h"
#include "PointEvent.h"
#include "SegmentEvent.h"

class SweepLine
{
private:
    std::priority_queue<PointEvent, std::vector<PointEvent>, std::greater<PointEvent>>
                              _pointQueue;     // 存储点事件的优先队列 ，排序规则在 point_event 里
    point2d_unordered_set     _allCrossPoints; // TODO: 不知道交点查找起来有什么规律，暂时用 hash 存
    std::vector<SegmentEvent> _segmentTree;    // TODO: 用 mutil_set 试试

public:
    SweepLine(std::vector<zong::geometry::SegmentF>& segmentVec);

    inline point2d_unordered_set GetAllCrossPoints() const { return _allCrossPoints; }

private:
    // 预处理函数
    void resetSegmentsPoints(std::vector<zong::geometry::SegmentF>& segments) const;

    void updateSegmentTree(double sweepLineXPos, double sweepLineYPos);
    void emplaceCrossPoint(int& a, int& b); // 用引用是为了改成红黑树的时候方便

public:
    void scan();
};