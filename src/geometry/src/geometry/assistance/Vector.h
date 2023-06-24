#pragma once

#include <math.h>

#include "../../util/math.h"

namespace zong
{
namespace geometry
{

class Point;

/**
 * \brief Vector
 * \brief Parmater is as same as point
 * \tparam double
 */
class Vector
{
private:
    double _x;
    double _y;

public:
    // explicit, avoid non-explicit as same as Point
    // non-explicit, the basic operation as same as Point
    explicit Vector() : _x(0), _y(0) {}
    explicit Vector(double const x, double const y) : _x(x), _y(y) {}
    // Vector(Point const& other);
    // copy-assignment
    // non-constructor

    inline double x() const { return _x; }
    inline double y() const { return _y; }

    inline double length() const { return sqrt(_x * _x + _y * _y); }

    inline void setX(double const x) { _x = x; }
    inline void setY(double const y) { _y = y; }

    // assignment
    static bool isEqual(Vector const& a, Vector const& b, double const precision);    // Add precision
    static bool isNotEqual(Vector const& a, Vector const& b, double const precision); // Add precision

    inline Vector operator+(Vector const& other) const { return Vector(x() + other.x(), y() + other.y()); }
    Point         operator+(Point const& other) const;
    inline Vector operator+=(Vector const& other)
    {
        setX(x() + other.x());
        setY(y() + other.y());
        return *this;
    }

    inline Vector operator-(Vector const& other) const { return Vector(x() - other.x(), y() - other.y()); }
    // Point         operator-(Point const& other) const;
    inline Vector operator-=(Vector const& other)
    {
        setX(x() - other.x());
        setY(y() - other.y());
        return *this;
    }

    inline Vector operator*(double const scale) const { return Vector(x() * scale, y() * scale); }
    inline Vector operator*=(double const scale)
    {
        setX(x() * scale);
        setY(y() * scale);
        return *this;
    }

    Vector normalize() const;
    double dot(Vector const& other) const;
    double cross(Vector const& other) const;
};

// typedef Vector DoubleVector;
// typedef Vector<int>    IntVector;

} // namespace geometry
} // namespace zong