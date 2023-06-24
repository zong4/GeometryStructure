#pragma once

#include <type_traits>

namespace zong
{
namespace util
{

inline bool isEqual(int const a, int const b, int const precision)
{
    return a - b < precision && a - b > -precision;
}

inline bool isNotEqual(int const a, int const b, int const precision)
{
    return !isEqual(a, b, precision);
}

inline bool isEqual(double const a, double const b, double const precision)
{
    return a - b < precision && a - b > -precision;
}

inline bool isNotEqual(double const a, double const b, double const precision)
{
    return !isEqual(a, b, precision);
}

// hyh add
// template <class OuterClass, class InnerClass>
// inline bool isEqual(OuterClass<InnerClass> const a, OuterClass<InnerClass> const b, int const precision)
//{
//     return isEqual(InnerClass a, InnerClass b, precision);
// }
//
// template <class OuterClass, class InnerClass>
// inline bool isEqual(OuterClass<InnerClass> const a, OuterClass<InnerClass> const b, double const precision)
//{
//     return a - b < precision && a - b > -precision;
// }

} // namespace util
} // namespace zong