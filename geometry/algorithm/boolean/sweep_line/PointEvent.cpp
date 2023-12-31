#include "PointEvent.h"

bool zong::PointEvent::operator==(PointEvent const& other) const
{
    if (!(*this < other) && !(*this > other))
        return true;
    else
        return false;
}

// 坐标值相同的节点事件在排序时
// 1. 首先应该把终点放在起点前面
// 2. 其次如果都是起点再继续比较另一个端点（终点）的纵坐标（优先）和横坐标。
bool zong::PointEvent::operator<(PointEvent const& other) const
{
    if (!IS_FLOAT_EQUAL(point().x(), other.point().x()))
        return point().x() < other.point().x();
    else if (!IS_FLOAT_EQUAL(point().y(), other.point().y()))
        return point().y() < other.point().y();
    else if (_eventType != other._eventType)
        return _eventType < other._eventType;
    else if (!IS_FLOAT_EQUAL(_otherEventSp->point().y(), other._otherEventSp->point().y()))
        return _otherEventSp->point().y() < other._otherEventSp->point().y();
    else
        return _otherEventSp->point().x() < other._otherEventSp->point().x();
}

// 坐标值相同的节点事件在排序时
// 1. 首先应该把终点放在起点前面
// 2. 其次如果都是起点再继续比较另一个端点（终点）的纵坐标（优先）和横坐标。
bool zong::PointEvent::operator>(PointEvent const& other) const
{
    if (!IS_FLOAT_EQUAL(point().x(), other.point().x()))
        return point().x() > other.point().x();
    else if (!IS_FLOAT_EQUAL(point().y(), other.point().y()))
        return point().y() > other.point().y();
    else if (_eventType != other._eventType)
        return _eventType > other._eventType;
    else if (!IS_FLOAT_EQUAL(_otherEventSp->point().y(), other._otherEventSp->point().y()))
        return _otherEventSp->point().y() > other._otherEventSp->point().y();
    else
        return _otherEventSp->point().x() > other._otherEventSp->point().x();
}
