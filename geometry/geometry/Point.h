#pragma once

#include "../util/math.h"
#include "assistance/Vector.h"

namespace zong
{

/**
 * \brief just one int point
 */
class Point
{
private:
    // TODO: optimize to _data[2]
    int _xPosition;
    int _yPosition;

public:
    explicit Point() : _xPosition(0), _yPosition(0) {}
    explicit Point(int const x, int const y) : _xPosition(x), _yPosition(y) {}

    inline int x() const { return _xPosition; }
    inline int y() const { return _yPosition; }

    inline void setX(int const x) { _xPosition = x; }
    inline void setY(int const y) { _yPosition = y; }

    static bool        isEqual(Point const& a, Point const& b, int const precision);
    inline static bool isNotEqual(Point const& a, Point const& b, int const precision) { return !Point::isEqual(a, b, precision); }

    /**
     * \brief Point + Point = Point
     * \param other another Point
     * \return Point
     */
    inline Point operator+(Point const& other) const { return Point(x() + other.x(), y() + other.y()); }

    /**
     * \brief Point += Point
     * \param other another Point
     * \return Point
     */
    Point operator+=(Point const& other);

    /**
     * \brief Point + Vector = Point
     * \param other another Vector
     * \return Point
     */
    inline Point operator+(Vector const& other) const { return Point(x() + other.x(), y() + other.y()); }

    /**
     * \brief Point - Point = Vector
     * \param other another Point
     * \return Vector
     */
    inline Vector operator-(Point const& other) const { return Vector(x() - other.x(), y() - other.y()); }

    /**
     * \brief Point - Vector = Point
     * \param other another Vector
     * \return Point
     */
    inline Point operator-(Vector const& other) const { return Point(x() - other.x(), y() - other.y()); }

    inline Point operator*(int const scale) const { return Point(x() * scale, y() * scale); }
    Point        operator*=(int const scale);
};

} // namespace zong