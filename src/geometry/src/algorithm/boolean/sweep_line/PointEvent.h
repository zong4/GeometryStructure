#pragma once

#include "../boolean_pch.h"

enum class EventType : int
{
    EndPoint   = 0,
    StartPoint = 1,
};

// 点事件
class PointEvent
{
private:
    zong::geometry::Point                 _point2d;      // 该点
    EventType                   _eventType;    // 点的类型
    std::shared_ptr<PointEvent> _otherEventSp; // 另一个相连的点

public:
    PointEvent() : _point2d(zong::geometry::Point()), _eventType(EventType::StartPoint), _otherEventSp(std::shared_ptr<PointEvent>()) {}
    PointEvent(const zong::geometry::Point& point2d, const EventType eventType)
        : _point2d(point2d), _eventType(eventType), _otherEventSp(std::shared_ptr<PointEvent>())
    {
    }
    PointEvent(const zong::geometry::Point& point2d, const EventType eventType, const std::shared_ptr<PointEvent>& otherEventSP) // 传入指针
        : _point2d(point2d), _eventType(eventType), _otherEventSp(otherEventSP)
    {
    }
    PointEvent(const zong::geometry::Point& point2d, const EventType eventType, const PointEvent& otherEvent) // 传入对象
        : _point2d(point2d), _eventType(eventType), _otherEventSp(std::make_shared<PointEvent>(otherEvent))
    {
    }
    PointEvent(const PointEvent& other) : _point2d(other._point2d), _eventType(other._eventType), _otherEventSp(other._otherEventSp)
    {
        // 太舒服了，共享指针的逻辑比原始指针的逻辑好多了，浅拷贝就能达到深拷贝的效果
        // m_otherEventSP = std::make_shared<PointEvent>(other.m_otherEventSP->_point2d, other.m_otherEventSP->_eventType,
        //                                               other.m_otherEventSP->m_otherEventSP);
    }

    bool operator==(const PointEvent& other) const;
    bool operator<(const PointEvent& other) const;
    bool operator>(const PointEvent& other) const;

    inline zong::geometry::Point                 point() const { return _point2d; }
    inline EventType                   eventType() const { return _eventType; }
    inline std::shared_ptr<PointEvent> otherEvent() const { return _otherEventSp; }

    void setEventType(const EventType eventType) { _eventType = eventType; }
    void setOtherEvent(const std::shared_ptr<PointEvent>& otherEvent) { _otherEventSp = otherEvent; }
};
