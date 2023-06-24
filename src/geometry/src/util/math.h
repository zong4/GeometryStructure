#pragma once

// zong may delete
#include <type_traits>

namespace zong
{
namespace util
{

const double HIGH_EPS = 1e-12;
const double EPS      = 1e-8;

inline bool isEqual(double const a, double const b, double const precision)
{
    return a - b < precision && a - b > -precision;
}

inline bool isNotEqual(double const a, double const b, double const precision)
{
    return !isEqual(a, b, precision);
}

} // namespace util
} // namespace zong