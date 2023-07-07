#include "Vector.h"

bool zong::Vector::isEqual(Vector const& a, Vector const& b, int const precision)
{
    return util::isEqual(a.x(), b.x(), precision) && util::isEqual(a.y(), b.y(), precision);
}

zong::Vector zong::Vector::operator+=(Vector const& other)
{
    *this = *this + other;
    return *this;
}

zong::Vector zong::Vector::operator-=(Vector const& other)
{
    *this = *this - other;
    return *this;
}

zong::Vector zong::Vector::operator*=(int const scale)
{
    *this = *this * scale;
    return *this;
}

zong::Vector zong::Vector::normalize(int const precision) const
{
    int const len = this->length();
    if (util::isEqual(len, 0, precision))
        return NormalVector;

    return Vector(this->x() / len, this->y() / len);
}

int zong::Vector::dot(Vector const& other) const
{
    return this->x() * other.x() + this->y() * other.y();
}

int zong::Vector::cross(Vector const& other) const
{
    return this->x() * other.y() - this->y() * other.x();
}

zong::Vector zong::Vector::NormalVector = zong::Vector(1, 1);
