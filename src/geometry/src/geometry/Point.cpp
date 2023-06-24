#include "Point.h"

#include "assistance/Vector.h"

namespace zong
{
namespace geometry
{

// Point::Point(Vector const& other) : _x(other.x()), _y(other.y())
//{
// }

bool Point::isEqual(Point const& a, Point const& b, double const precision)
{
    return util::isEqual(a.x(), b.x(), precision) && util::isEqual(a.y(), b.y(), precision);
}

bool Point::isNotEqual(Point const& a, Point const& b, double const precision)
{
    return !Point::isEqual(a, b, precision);
}

Point Point::operator+(Point const& other) const
{
    return Point(x() + other.x(), y() + other.y());
}

Point Point::operator+(Vector const& other) const
{
    return Point(x() + other.x(), y() + other.y());
}

Vector Point::operator-(Point const& other) const
{
    return Vector(x() - other.x(), y() - other.y());
}

Point Point::operator-(Vector const& other) const
{
    return Point(x() - other.x(), y() - other.y());
}

} // namespace geometry
} // namespace zong
