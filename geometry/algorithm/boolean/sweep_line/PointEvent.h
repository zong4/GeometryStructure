#pragma once

#include "../boolean_pch.h"

namespace zong
{

/**
 * \brief martinez sweep line only needs two types \n
 * EndPoint = 0, which help for sorting
 */
enum class EventType : int
{
    EndPoint   = 0,
    StartPoint = 1,
};

/**
 * \brief a point carry a type(start point or end point) and a pointer to another point
 */
class PointEvent
{
private:
    zong::PointF                _point;
    EventType                   _eventType;
    std::shared_ptr<PointEvent> _otherEventSp;

public:
    PointEvent() : _point(zong::PointF()), _eventType(EventType::StartPoint), _otherEventSp(nullptr) {}
    PointEvent(zong::PointF const& point, EventType const eventType) : _point(point), _eventType(eventType), _otherEventSp(nullptr) {}
    PointEvent(zong::PointF const& point, EventType const eventType, std::shared_ptr<PointEvent> const otherEventSp)
        : _point(point), _eventType(eventType), _otherEventSp(otherEventSp)
    {
    }
    PointEvent(zong::PointF const& point, EventType const eventType, PointEvent const& otherEvent)
        : _point(point), _eventType(eventType), _otherEventSp(std::make_shared<PointEvent>(otherEvent))
    {
    }
    PointEvent(PointEvent const& other) : _point(other._point), _eventType(other._eventType), _otherEventSp(other._otherEventSp) {}

    inline zong::PointF                point() const { return _point; }
    inline EventType                   eventType() const { return _eventType; }
    inline std::shared_ptr<PointEvent> otherEvent() const { return _otherEventSp; }

    void setEventType(EventType const eventType) { _eventType = eventType; }
    void setOtherEvent(std::shared_ptr<PointEvent> const otherEvent) { _otherEventSp = otherEvent; }

    bool operator==(const PointEvent& other) const;
    bool operator<(const PointEvent& other) const;
    bool operator>(const PointEvent& other) const;
};

} // namespace zong
