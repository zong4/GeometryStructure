#include "Vector.h"

// template <util::IsNumber int>
zong::geometry::Vector zong::geometry::Vector::normalize(int const precision) const
{
    int const len = this->length();
    if (util::isEqual(len, 0, precision))
        return NormalVector;

    return Vector(this->x() / len, this->y() / len);
}

// template <util::IsNumber int>
int zong::geometry::Vector::dot(Vector const& other) const
{
    return this->x() * other.x() + this->y() * other.y();
}

// template <util::IsNumber int>
int zong::geometry::Vector::cross(Vector const& other) const
{
    return this->x() * other.y() - this->y() * other.x();
}

zong::geometry::Vector zong::geometry::Vector::NormalVector = zong::geometry::Vector(1, 1);
