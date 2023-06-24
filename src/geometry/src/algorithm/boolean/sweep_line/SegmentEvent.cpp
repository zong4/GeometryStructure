#include "SegmentEvent.h"

SegmentEvent::SegmentEvent(PointEvent const& pointEvent, PointEvent const& anotherPointEvent)
{
    if (pointEvent.eventType() == EventType::StartPoint)
    {
        _segment2d.setFirst(pointEvent.point());
        _segment2d.setSecond(anotherPointEvent.point());
        _startPointEvent = pointEvent;
    }
    else
    {
        _segment2d.setFirst(anotherPointEvent.point());
        _segment2d.setSecond(pointEvent.point());
        _startPointEvent = anotherPointEvent;
    }

    _sweepLineCrossPoint = _segment2d.first();

    if (_segment2d.first().x() == _segment2d.second().x())
    {
        _isNoK = true;
        _k     = 0;
    }
    else
    {
        _isNoK = false;
        _k     = (_segment2d.second().y() - _segment2d.first().y()) / (_segment2d.second().x() - _segment2d.first().x());
    }
}

SegmentEvent SegmentEvent::operator=(SegmentEvent const& other)
{
    this->_segment2d           = other._segment2d;
    this->_startPointEvent     = other._startPointEvent;
    this->_sweepLineCrossPoint = other._sweepLineCrossPoint;
    this->_k                   = other._k;
    this->_isNoK               = other._isNoK;
    return *this;
}

bool SegmentEvent::operator==(SegmentEvent const& other) const
{
    if (!(*this < other) && !(*this > other))
        return true;
    else
        return false;
}

// 默认从左下到右上
bool SegmentEvent::operator<(SegmentEvent const& other) const
{
    if (!IS_FLOAT_EQUAL(this->_segment2d.first().x(), other._segment2d.first().x()))
        return this->_segment2d.first().x() < other._segment2d.first().x();
    else if (!IS_FLOAT_EQUAL(this->_segment2d.first().y(), other._segment2d.first().y()))
        return this->_segment2d.first().y() < other._segment2d.first().y();
    else if (!IS_FLOAT_EQUAL(this->_segment2d.second().x(), other._segment2d.second().x()))
        return this->_segment2d.second().x() < other._segment2d.second().x();
    else
        return this->_segment2d.second().y() < other._segment2d.second().y();
}

// 默认从左下到右上
bool SegmentEvent::operator>(SegmentEvent const& other) const
{
    if (!IS_FLOAT_EQUAL(this->_segment2d.first().x(), other._segment2d.first().x()))
        return this->_segment2d.first().x() > other._segment2d.first().x();
    else if (!IS_FLOAT_EQUAL(this->_segment2d.first().y(), other._segment2d.first().y()))
        return this->_segment2d.first().y() > other._segment2d.first().y();
    else if (!IS_FLOAT_EQUAL(this->_segment2d.second().x(), other._segment2d.second().x()))
        return this->_segment2d.second().x() > other._segment2d.second().x();
    else
        return this->_segment2d.second().y() > other._segment2d.second().y();
}

// 默认扫描线垂直 x 轴，从左到右，不好改扫描线方向，改的话比较函数也要一起改
void SegmentEvent::updateSweepLineCrossPoint(const double x, const double y)
{
    if (_isNoK)
    {
        _sweepLineCrossPoint.setY(y);
    }
    else
    {
        _sweepLineCrossPoint.setX(x);
        _sweepLineCrossPoint.setY(_k * (x - _segment2d.first().x()) + _segment2d.first().y());
    }
}
