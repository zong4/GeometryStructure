#pragma once

#include <variant>

#include "../../util/math.h"
#include <math.h>

namespace zong
{
namespace geometry
{

/**
 * \brief int vector, parameter is as same as Point<int>
 */
class Vector
{
private:
    // TODO: optimize to _data[2]
    int _xDisplacement;
    int _yDisplacement;

public:
    explicit Vector() : _xDisplacement(0), _yDisplacement(0) {}
    explicit Vector(int const x, int const y) : _xDisplacement(x), _yDisplacement(y) {}

    inline int x() const { return _xDisplacement; }
    inline int y() const { return _yDisplacement; }

    inline int length() const { return static_cast<int>(sqrt(x() * x() + y() * y())); }

    inline void setX(int const x) { _xDisplacement = x; }
    inline void setY(int const y) { _yDisplacement = y; }

    inline static bool isEqual(Vector const& a, Vector const& b, int const precision)
    {
        return util::isEqual(a.x(), b.x(), precision) && util::isEqual(a.y(), b.y(), precision);
    }

    inline static bool isNotEqual(Vector const& a, Vector const& b, int const precision) { return !Vector::isEqual(a, b, precision); }

    /**
     * \brief Vector + Vector = Vector
     * \param other another Vector
     * \return Vector
     */
    inline Vector operator+(Vector const& other) const { return Vector(x() + other.x(), y() + other.y()); }

    /**
     * \brief Vector += Vector
     * \param other another Vector
     * \return Vector
     */
    inline Vector operator+=(Vector const& other)
    {
        setX(x() + other.x());
        setY(y() + other.y());
        return *this;
    }

    /**
     * \brief Vector - Vector = Vector
     * \param other another Vector
     * \return Vector
     */
    inline Vector operator-(Vector const& other) const { return Vector(x() - other.x(), y() - other.y()); }

    /**
     * \brief Vector -= Vector
     * \param other another Vector
     * \return Vector
     */
    inline Vector operator-=(Vector const& other)
    {
        setX(x() - other.x());
        setY(y() - other.y());
        return *this;
    }

    inline Vector operator*(int const scale) const { return Vector(x() * scale, y() * scale); }
    inline Vector operator*=(int const scale)
    {
        setX(x() * scale);
        setY(y() * scale);
        return *this;
    }

    Vector normalize(int const precision) const;
    int    dot(Vector const& other) const;
    int    cross(Vector const& other) const;

    static Vector NormalVector;
};

} // namespace geometry
} // namespace zong