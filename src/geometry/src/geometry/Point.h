#pragma once

#include "../util/math.h"

namespace zong
{
namespace geometry
{

class Vector;

/**
 * \brief Point
 * \brief Jusr one point
 * \tparam double
 */
class Point
{
private:
    double _x;
    double _y;

public:
    // explicit, avoid non-explicit as same as Vector
    // non-explicit, the basic operation as same as Vector assistance
    explicit Point() : _x(0), _y(0) {}
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

    // zong give a explain
    Point        operator+(Point const& other) const;
    Point        operator+(Vector const& other) const;
    inline Point operator+=(Point const& other)
    {
        setX(x() + other.x());
        setY(y() + other.y());
        return *this;
    }

    Vector operator-(Point const& other) const;
    Point  operator-(Vector const& other) const;
    // inline Point operator-=(Point const& other)
    //{
    //     setX(x() - other.x());
    //     setY(y() - other.y());
    //     return *this;
    // }

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