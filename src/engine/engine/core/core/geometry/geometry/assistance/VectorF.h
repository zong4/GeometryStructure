#pragma once

#include <math.h>

#include "../../util/concept.h"
#include "../../util/math.h"

namespace zong
{

/**
 * \brief double vector, parameter is as same as PointF
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

    static bool        isEqual(VectorF const& a, VectorF const& b, double const precision);
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
    VectorF operator+=(VectorF const& other);

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
    VectorF operator-=(VectorF const& other);

    inline VectorF operator*(double const scale) const { return VectorF(x() * scale, y() * scale); }
    VectorF        operator*=(double const scale);

    VectorF normalize(double const precision) const;
    double  dot(VectorF const& other) const;
    double  cross(VectorF const& other) const;

    static VectorF NormalVectorF;
};

} // namespace zong