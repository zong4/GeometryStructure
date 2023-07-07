#include "VectorF.h"

bool zong::VectorF::isEqual(VectorF const& a, VectorF const& b, double const precision)
{
    return util::isEqual(a.x(), b.x(), precision) && util::isEqual(a.y(), b.y(), precision);
}

zong::VectorF zong::VectorF::operator+=(VectorF const& other)
{
    *this = *this + other;
    return *this;
}

zong::VectorF zong::VectorF::operator-=(VectorF const& other)
{
    *this = *this - other;
    return *this;
}

zong::VectorF zong::VectorF::operator*=(double const scale)
{
    *this = *this * scale;
    return *this;
}

// template <util::IsNumber double>
zong::VectorF zong::VectorF::normalize(double const precision) const
{
    double const len = this->length();
    if (util::isEqual(len, 0.0, precision))
        return NormalVectorF;

    return VectorF(this->x() / len, this->y() / len);
}

// template <util::IsNumber double>
double zong::VectorF::dot(VectorF const& other) const
{
    return this->x() * other.x() + this->y() * other.y();
}

// template <util::IsNumber double>
double zong::VectorF::cross(VectorF const& other) const
{
    return this->x() * other.y() - this->y() * other.x();
}

zong::VectorF zong::VectorF::NormalVectorF = zong::VectorF(1.0, 1.0);
