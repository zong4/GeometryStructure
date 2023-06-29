#include "PointEvent.h"

bool PointEvent::operator==(PointEvent const& other) const
{
    if (!(*this < other) && !(*this > other))
        return true;
    else
        return false;
}

// 坐标值相同的节点事件在排序时
// 1. 首先应该把终点放在起点前面
// 2. 其次如果都是起点再继续比较另一个端点（终点）的纵坐标（优先）和横坐标。
bool PointEvent::operator<(PointEvent const& other) const
{
    if (!IS_FLOAT_EQUAL(_point2d.x(), other._point2d.x()))
        return _point2d.x() < other._point2d.x();
    else if (!IS_FLOAT_EQUAL(_point2d.y(), other._point2d.y()))
        return _point2d.y() < other._point2d.y();
    else if (_eventType != other._eventType)
        return _eventType < other._eventType;
    else if (!IS_FLOAT_EQUAL(_otherEventSp->_point2d.y(), other._otherEventSp->_point2d.y()))
        return _otherEventSp->_point2d.y() < other._otherEventSp->_point2d.y();
    else
        return _otherEventSp->_point2d.x() < other._otherEventSp->_point2d.x();
}

// 坐标值相同的节点事件在排序时
// 1. 首先应该把终点放在起点前面
// 2. 其次如果都是起点再继续比较另一个端点（终点）的纵坐标（优先）和横坐标。
bool PointEvent::operator>(PointEvent const& other) const
{
    if (!IS_FLOAT_EQUAL(_point2d.x(), other._point2d.x()))
        return _point2d.x() > other._point2d.x();
    else if (!IS_FLOAT_EQUAL(_point2d.y(), other._point2d.y()))
        return _point2d.y() > other._point2d.y();
    else if (_eventType != other._eventType)
        return _eventType > other._eventType;
    else if (!IS_FLOAT_EQUAL(_otherEventSp->_point2d.y(), other._otherEventSp->_point2d.y()))
        return _otherEventSp->_point2d.y() > other._otherEventSp->_point2d.y();
    else
        return _otherEventSp->_point2d.x() > other._otherEventSp->_point2d.x();
}
