#pragma once

#include "../boolean_pch.h"
#include "PointEvent.h"

namespace zong
{

class SegmentEvent
{
private:
    zong::SegmentF      _segment2d;           // 该线段，优化的时候可以考虑去掉这个变量
    PointEvent          _startPointEvent;     // 起点事件，用来查找另一点的事件
    zong::PointF _sweepLineCrossPoint; // 与扫描线的交点，用来排序
    double              _k;                   // 斜率
    bool                _isNoK;               // 是否平行扫描线（扫描线默认垂直 x 轴）

public:
    SegmentEvent(PointEvent const& pointEvent, PointEvent const& anotherPointEvent);
    SegmentEvent(SegmentEvent const& other)
        : _segment2d(other._segment2d),
          _startPointEvent(other._startPointEvent),
          _sweepLineCrossPoint(other._sweepLineCrossPoint),
          _k(other._k),
          _isNoK(other._isNoK)
    {
    }

    SegmentEvent operator=(SegmentEvent const& other);
    bool         operator==(SegmentEvent const& other) const;
    bool         operator<(SegmentEvent const& other) const;
    bool         operator>(SegmentEvent const& other) const;

    inline zong::SegmentF      segment() const { return _segment2d; }
    inline PointEvent          startPointEvent() const { return _startPointEvent; }
    inline zong::PointF sweepLineCrossPoint() const { return _sweepLineCrossPoint; }
    inline bool                isNoK() const { return _isNoK; }

    inline void setSegmentSecond(zong::PointF const& second) { _segment2d.setSecond(second); }
    inline void setSegmentSecond(PointEvent const& secondPointEvent) { _segment2d.setSecond(secondPointEvent.point()); }

    inline void setStartPointEvent(const PointEvent& startPointEvent)
    {
        _startPointEvent = startPointEvent;
    } // TODO: 不知道为什么加 & 会报错

public:
    // TODO: 应该设成 private: 的，不过要先给树设个友元
    void updateSweepLineCrossPoint(double x, double y);
};

} // namespace zong