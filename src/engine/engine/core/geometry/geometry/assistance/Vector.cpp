#include "Vector.h"

// template <util::IsNumber int>
zong::Vector zong::Vector::normalize(int const precision) const
{
    int const len = this->length();
    if (util::isEqual(len, 0, precision))
        return NormalVector;

    return Vector(this->x() / len, this->y() / len);
}

// template <util::IsNumber int>
int zong::Vector::dot(Vector const& other) const
{
    return this->x() * other.x() + this->y() * other.y();
}

// template <util::IsNumber int>
int zong::Vector::cross(Vector const& other) const
{
    return this->x() * other.y() - this->y() * other.x();
}

zong::Vector zong::Vector::NormalVector = zong::Vector(1, 1);
