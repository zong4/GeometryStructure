#pragma once

#include "../utils/bit.h"

namespace zong
{

enum class EventCategory : int
{
    None                     = 0,
    EventCategoryApplication = BIT(0),
    EventCategoryInput       = BIT(1),
    EventCategoryKeyboard    = BIT(2),
    EventCategoryMouse       = BIT(3),
    EventCategoryMouseButton = BIT(4)
};

inline int operator|(EventCategory const value1, int const value2)
{
    return static_cast<int>(value1) | value2;
}

inline int operator|(EventCategory const value1, EventCategory const value2)
{
    return static_cast<int>(value1) | static_cast<int>(value2);
}

inline int operator&(EventCategory const value1, int const value2)
{
    return static_cast<int>(value1) & value2;
}

inline int operator&(EventCategory const value1, EventCategory const value2)
{
    return static_cast<int>(value1) & static_cast<int>(value2);
}

} // namespace zong