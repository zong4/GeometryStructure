#include "Point.h"

bool zong::Point::isEqual(Point const& a, Point const& b, int const precision)
{
    return util::isEqual(a.x(), b.x(), precision) && util::isEqual(a.y(), b.y(), precision);
}

zong::Point zong::Point::operator+=(Point const& other)
{
    *this = *this + other;
    return *this;
}

zong::Point zong::Point::operator*=(int const scale)
{
    *this = *this * scale;
    return *this;
}