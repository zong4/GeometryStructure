#pragma once

namespace zong
{
namespace util
{

constexpr double EPS_DOUBLE      = 1e-8;
constexpr double HIGH_EPS_DOUBLE = 1e-12;

inline bool isEqual(int const a, int const b, int const precision)
{
    return a - b < precision && a - b > -precision;
}

inline bool isNotEqual(int const a, int const b, int const precision)
{
    return !isEqual(a, b, precision);
}

inline bool isGreater(int const a, int const b, int const precision)
{
    return a - b >= precision;
}

inline bool isGreaterEqual(int const a, int const b, int const precision)
{
    return a - b > -precision;
}

inline bool isLess(int const a, int const b, int const precision)
{
    return a - b <= -precision;
}

inline bool isLessEqual(int const a, int const b, int const precision)
{
    return a - b < precision;
}

inline bool isEqual(double const a, double const b, double const precision)
{
    return a - b < precision && a - b > -precision;
}

inline bool isNotEqual(double const a, double const b, double const precision)
{
    return !isEqual(a, b, precision);
}

inline bool isGreater(double const a, double const b, double const precision)
{
    return a - b >= precision;
}

inline bool isGreaterEqual(double const a, double const b, double const precision)
{
    return a - b > -precision;
}

inline bool isLess(double const a, double const b, double const precision)
{
    return a - b <= -precision;
}

inline bool isLessEqual(double const a, double const b, double const precision)
{
    return a - b < precision;
}

} // namespace util
} // namespace zong