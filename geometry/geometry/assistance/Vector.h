#pragma once

#include <math.h>

#include <variant>

#include "../../util/math.h"

namespace zong
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

    static bool        isEqual(Vector const& a, Vector const& b, int const precision);
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
    Vector operator+=(Vector const& other);

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
    Vector operator-=(Vector const& other);

    inline Vector operator*(int const scale) const { return Vector(x() * scale, y() * scale); }
    Vector        operator*=(int const scale);

    Vector normalize(int const precision) const;
    int    dot(Vector const& other) const;
    int    cross(Vector const& other) const;

    static Vector NormalVector;
};

} // namespace zong