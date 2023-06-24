#include "Vector.h"

#include "../../util/math.h"
#include "../Point.h"

namespace zong
{
namespace geometry
{

// Vector::Vector(Point const& other) : _x(other.x()), _y(other.y())
//{
// }

bool Vector::isEqual(Vector const& a, Vector const& b, double const precision)
{
    return util::isEqual(a.x(), b.x(), precision) && util::isEqual(a.y(), b.y(), precision);
}

bool Vector::isNotEqual(Vector const& a, Vector const& b, double const precision)
{
    return !Vector::isEqual(a, b, precision);
}

Point Vector::operator+(Point const& other) const
{
    return Point(x() + other.x(), y() + other.y());
}

Vector Vector::normalize() const
{
    return Vector(this->x() / this->length(), this->y() / this->length());
}

double Vector::dot(Vector const& other) const
{
    return this->x() * other.x() + this->y() * other.y();
}

double Vector::cross(Vector const& other) const
{
    return this->x() * other.y() - this->y() * other.x();
}

} // namespace geometry
} // namespace zong
