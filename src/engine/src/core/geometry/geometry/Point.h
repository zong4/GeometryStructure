#pragma once

#include "../util/concept.h"
#include "../util/math.h"
#include "assistance/VectorF.h"

namespace zong
{
namespace geometry
{

/**
 * \brief just one value_type point
 * \tparam value_type double or int
 */
template <util::IsNumber value_type>
class Point
{
private:
    // TODO: optimize to _data[2]
    value_type _xPosition;
    value_type _yPosition;

public:
    explicit Point<value_type>() : _xPosition(0.0), _yPosition(0.0) {}
    explicit Point<value_type>(value_type const x, value_type const y) : _xPosition(x), _yPosition(y) {}

    inline value_type x() const { return _xPosition; }
    inline value_type y() const { return _yPosition; }

    inline void setX(value_type const x) { _xPosition = x; }
    inline void setY(value_type const y) { _yPosition = y; }

    inline static bool isEqual(Point<value_type> const& a, Point<value_type> const& b, value_type const precision)
    {
        return util::isEqual(a.x(), b.x(), precision) && util::isEqual(a.y(), b.y(), precision);
    }

    inline static bool isNotEqual(Point<value_type> const& a, Point<value_type> const& b, value_type const precision)
    {
        return !Point<value_type>::isEqual(a, b, precision);
    }

    /**
     * \brief Point<value_type> + Point<value_type> = Point<value_type>
     * \param other another Point<value_type>
     * \return Point<value_type>
     */
    inline Point<value_type> operator+(Point<value_type> const& other) const { return Point<value_type>(x() + other.x(), y() + other.y()); }

    /**
     * \brief Point<value_type> += Point<value_type>
     * \param other another Point<value_type>
     * \return Point<value_type>
     */
    inline Point<value_type> operator+=(Point<value_type> const& other)
    {
        setX(x() + other.x());
        setY(y() + other.y());
        return *this;
    }

    /**
     * \brief Point<value_type> + VectorF = Point<value_type>
     * \param other another VectorF
     * \return Point<value_type>
     */
    inline Point<value_type> operator+(VectorF const& other) const { return Point<value_type>(x() + other.x(), y() + other.y()); }

    /**
     * \brief Point<value_type> - Point<value_type> = VectorF
     * \param other another Point<value_type>
     * \return VectorF
     */
    inline VectorF operator-(Point<value_type> const& other) const { return VectorF(x() - other.x(), y() - other.y()); }

    /**
     * \brief Point<value_type> - VectorF = Point<value_type>
     * \param other another VectorF
     * \return Point<value_type>
     */
    inline Point<value_type> operator-(VectorF const& other) const { return Point<value_type>(x() - other.x(), y() - other.y()); }

    inline Point<value_type> operator*(value_type const scale) const { return Point<value_type>(x() * scale, y() * scale); }
    inline Point<value_type> operator*=(value_type const scale)
    {
        setX(x() * scale);
        setY(y() * scale);
        return *this;
    }
};

template <class PointType>
concept IsPoint = std::is_same_v<PointType, Point<int>> || std::is_same_v<PointType, Point<double>>;

} // namespace geometry
} // namespace zong