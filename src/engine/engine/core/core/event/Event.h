#pragma once

#include "EventCategory.h"
#include "EventType.h"

namespace zong
{

class Event
{
private:
    bool _handled;

public:
    Event() : _handled(false) {}
    virtual ~Event() = default;

    inline bool handled() const { return _handled; }

    virtual EventType     eventType() const    = 0;
    virtual std::string   name() const         = 0;
    virtual EventCategory categoryFlag() const = 0;

    inline void setHandled(bool const value) { _handled = value; }

    virtual bool isInCategory(EventCategory const category) const { return categoryFlag() & category; }

#ifdef DEBUG
    inline virtual std::string toString() const { return "EventName: " + name(); }
#endif
};

} // namespace zong

#define EVENT_CLASS_TYPE(type)                   \
    static EventType staticType()                \
    {                                            \
        return EventType::type;                  \
    }                                            \
    virtual EventType eventType() const override \
    {                                            \
        return staticType();                     \
    }                                            \
    virtual std::string name() const override    \
    {                                            \
        return #type;                            \
    }

#define EVENT_CLASS_CATEGORY(category)                  \
    virtual EventCategory categoryFlag() const override \
    {                                                   \
        return category;                                \
    }
