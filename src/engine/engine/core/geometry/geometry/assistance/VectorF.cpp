#include "VectorF.h"

// template <util::IsNumber double>
zong::geometry::VectorF zong::geometry::VectorF::normalize(double const precision) const
{
    double const len = this->length();
    if (util::isEqual(len, 0.0, precision))
        return NormalVectorF;

    return VectorF(this->x() / len, this->y() / len);
}

// template <util::IsNumber double>
double zong::geometry::VectorF::dot(VectorF const& other) const
{
    return this->x() * other.x() + this->y() * other.y();
}

// template <util::IsNumber double>
double zong::geometry::VectorF::cross(VectorF const& other) const
{
    return this->x() * other.y() - this->y() * other.x();
}

zong::geometry::VectorF zong::geometry::VectorF::NormalVectorF = zong::geometry::VectorF(1.0, 1.0);
