#pragma once

#include <vector>

#include "Point.h"
#include "assistance/BoundingBoxF.h"

namespace zong
{
namespace geometry
{

/**
 * \brief Separate: separate \n
 *  Intersection: intersection \n
 *  Overlap: overlap, not means two cross points, it also maybe one cross point \n
 *  (remove)Unknown: the state is unknown, return this is because one segment is a point
 */
enum class SegmentIntersectionState : int
{
    Separate,
    Intersection,
    Overlap,
    // Unknown,
};

/**
 * \brief any double segment, also can be a point(warning)
 */
class SegmentF
{
private:
    Point<double> _first;
    Point<double> _second;

public:
    SegmentF() : _first(Point<double>()), _second(Point<double>()) {}
    SegmentF(Point<double> const& first, Point<double> const& second) : _first(first), _second(second) {}

    inline Point<double> first() const { return _first; }
    inline Point<double> second() const { return _second; }

    /**
     * \brief is this segment // y axis
     * \param precision precision
     * \return true: not // \n
     * false: //
     */
    bool haveK(double const precision) const;

    /**
     * \brief if no slope, it will warning, else return slope
     * \param precision precision
     * \return slope
     */
    double k(double const precision) const;

    BoundingBoxF box() const;

    inline void setFirst(Point<double> const& first) { _first = first; }
    inline void setSecond(Point<double> const& second) { _second = second; }

    static bool isEqual(SegmentF const& a, SegmentF const& b, double const precision);
    static bool isNotEqual(SegmentF const& a, SegmentF const& b, double const precision);

    /**
     * \brief use [cross test](https://blog.csdn.net/tengchongwei/article/details/72922056) to judge intersection state
     * \param other another segment
     * \param precision precision
     * \return SegmentIntersectionState
     */
    SegmentIntersectionState isIntersection(SegmentF const& other, double const precision) const;

    /**
     * \brief use [similar triangle](https://blog.csdn.net/fengkeyleaf/article/details/117692109) to get cross points
     * \param other another segment
     * \param precision precision
     * \return cross points \n
     * if return two points, they will sort by less x position and then less y position
     */
    std::vector<Point<double>> intersection(SegmentF const& other, double const precision) const;

private:
    /**
     * \brief if this segment is a point, it will warning
     * \param precision it will use util::HIGH_EPS if no precision in
     * \return true: a segment \n
     * false: a point
     */
    inline bool isValid(double const precision = util::HIGH_EPS_DOUBLE) const;
};

} // namespace geometry
} // namespace zong