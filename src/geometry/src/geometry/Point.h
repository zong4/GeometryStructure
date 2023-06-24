#pragma once

#include "assistance/Vector.h"

namespace zong
{
namespace geometry
{

class Vector;

/// <summary>
/// just one double point
/// </summary>
class Point
{
private:
    double _x;
    double _y;

public:
    /// <summary>
    /// explicit constructor
    /// </summary>
    explicit Point() : _x(0.0), _y(0.0) {}

    /// <summary>
    /// explicit constructor
    /// </summary>
    /// <param name="x">x position</param>
    /// <param name="y">y position</param>
    explicit Point(double const x, double const y) : _x(x), _y(y) {}
    // Point(Vector const& other);
    // copy-assignment
    // non-constructor

    inline double x() const { return _x; }
    inline double y() const { return _y; }

    inline void setX(double const x) { _x = x; }
    inline void setY(double const y) { _y = y; }

    // assignment
    static bool isEqual(Point const& a, Point const& b, double const precision);    // Add precision
    static bool isNotEqual(Point const& a, Point const& b, double const precision); // Add precision

    /// <summary>
    /// Point + Point = Point
    /// </summary>
    /// <param name="other">another Point</param>
    /// <returns>Point</returns>
    Point        operator+(Point const& other) const { return Point(x() + other.x(), y() + other.y()); }
    inline Point operator+=(Point const& other)
    {
        setX(x() + other.x());
        setY(y() + other.y());
        return *this;
    }

    /// <summary>
    /// Point + Vector = Point
    /// </summary>
    /// <param name="other">another Vector</param>
    /// <returns>Point</returns>
    Point operator+(Vector const& other) const { return Point(x() + other.x(), y() + other.y()); }

    /// <summary>
    /// Point - Point = Vector
    /// </summary>
    /// <param name="other">another Point</param>
    /// <returns>Vector</returns>
    Vector operator-(Point const& other) const { return Vector(x() - other.x(), y() - other.y()); }

    /// <summary>
    /// Point - Vector = Point
    /// </summary>
    /// <param name="other">another Vector</param>
    /// <returns>Point</returns>
    Point operator-(Vector const& other) const { return Point(x() - other.x(), y() - other.y()); }

    inline Point operator*(double const scale) const { return Point(x() * scale, y() * scale); }
    inline Point operator*=(double const scale)
    {
        setX(x() * scale);
        setY(y() * scale);
        return *this;
    }
};

// typedef Point      DoublePoint;
// typedef Point<int> IntPoint;

} // namespace geometry
} // namespace zong