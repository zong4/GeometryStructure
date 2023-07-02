#include "PointF.h"

bool zong::PointF::isEqual(PointF const& a, PointF const& b, double const precision)
{
    return util::isEqual(a.x(), b.x(), precision) && util::isEqual(a.y(), b.y(), precision);
}

zong::PointF zong::PointF::operator+=(PointF const& other)
{
    *this = *this + other;
    return *this;
}

zong::PointF zong::PointF::operator*=(double const scale)
{
    *this = *this * scale;
    return *this;
}