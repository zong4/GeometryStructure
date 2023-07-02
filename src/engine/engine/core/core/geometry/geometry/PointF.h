#pragma once

#include "../util/math.h"
#include "assistance/VectorF.h"

namespace zong
{

/**
 * \brief just one double point
 */
class PointF
{
private:
    // TODO: optimize to _data[2]
    double _xPosition;
    double _yPosition;

public:
    explicit PointF() : _xPosition(0.0), _yPosition(0.0) {}
    explicit PointF(double const x, double const y) : _xPosition(x), _yPosition(y) {}

    inline double x() const { return _xPosition; }
    inline double y() const { return _yPosition; }

    inline void setX(double const x) { _xPosition = x; }
    inline void setY(double const y) { _yPosition = y; }

    static bool        isEqual(PointF const& a, PointF const& b, double const precision);
    inline static bool isNotEqual(PointF const& a, PointF const& b, double const precision) { return !PointF::isEqual(a, b, precision); }

    /**
     * \brief PointF + PointF = PointF
     * \param other another PointF
     * \return PointF
     */
    inline PointF operator+(PointF const& other) const { return PointF(x() + other.x(), y() + other.y()); }

    /**
     * \brief PointF += PointF
     * \param other another PointF
     * \return PointF
     */
    PointF operator+=(PointF const& other);

    /**
     * \brief PointF + VectorF = PointF
     * \param other another VectorF
     * \return PointF
     */
    inline PointF operator+(VectorF const& other) const { return PointF(x() + other.x(), y() + other.y()); }

    /**
     * \brief PointF - PointF = VectorF
     * \param other another PointF
     * \return VectorF
     */
    inline VectorF operator-(PointF const& other) const { return VectorF(x() - other.x(), y() - other.y()); }

    /**
     * \brief PointF - VectorF = PointF
     * \param other another VectorF
     * \return PointF
     */
    inline PointF operator-(VectorF const& other) const { return PointF(x() - other.x(), y() - other.y()); }

    inline PointF operator*(double const scale) const { return PointF(x() * scale, y() * scale); }
    PointF        operator*=(double const scale);
};

} // namespace zong