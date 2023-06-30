#pragma once

#include "../../util/concept.h"
#include "../../util/math.h"
#include <math.h>

namespace zong
{
namespace geometry
{

/**
 * \brief double vector, parameter is as same as Point<double>
 */
class VectorF
{
private:
    // TODO: optimize to _data[2]
    double _xDisplacement;
    double _yDisplacement;

public:
    explicit VectorF() : _xDisplacement(0.0), _yDisplacement(0.0) {}
    explicit VectorF(double const x, double const y) : _xDisplacement(x), _yDisplacement(y) {}

    inline double x() const { return _xDisplacement; }
    inline double y() const { return _yDisplacement; }

    inline double length() const { return sqrt(x() * x() + y() * y()); }

    inline void setX(double const x) { _xDisplacement = x; }
    inline void setY(double const y) { _yDisplacement = y; }

    inline static bool isEqual(VectorF const& a, VectorF const& b, double const precision)
    {
        return util::isEqual(a.x(), b.x(), precision) && util::isEqual(a.y(), b.y(), precision);
    }

    inline static bool isNotEqual(VectorF const& a, VectorF const& b, double const precision) { return !VectorF::isEqual(a, b, precision); }

    /**
     * \brief VectorF + VectorF = VectorF
     * \param other another VectorF
     * \return VectorF
     */
    inline VectorF operator+(VectorF const& other) const { return VectorF(x() + other.x(), y() + other.y()); }

    /**
     * \brief VectorF += VectorF
     * \param other another VectorF
     * \return VectorF
     */
    inline VectorF operator+=(VectorF const& other)
    {
        setX(x() + other.x());
        setY(y() + other.y());
        return *this;
    }

    /**
     * \brief VectorF - VectorF = VectorF
     * \param other another VectorF
     * \return VectorF
     */
    inline VectorF operator-(VectorF const& other) const { return VectorF(x() - other.x(), y() - other.y()); }

    /**
     * \brief VectorF -= VectorF
     * \param other another VectorF
     * \return VectorF
     */
    inline VectorF operator-=(VectorF const& other)
    {
        setX(x() - other.x());
        setY(y() - other.y());
        return *this;
    }

    inline VectorF operator*(double const scale) const { return VectorF(x() * scale, y() * scale); }
    inline VectorF operator*=(double const scale)
    {
        setX(x() * scale);
        setY(y() * scale);
        return *this;
    }

    VectorF normalize(double const precision) const;
    double  dot(VectorF const& other) const;
    double  cross(VectorF const& other) const;

    static VectorF NormalVectorF;
};

} // namespace geometry
} // namespace zong