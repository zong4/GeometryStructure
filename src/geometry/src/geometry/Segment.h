#pragma once

#include <vector>

#include "../util/math.h"
#include "Point.h"

namespace zong
{
namespace geometry
{

enum class SegmentIntersectionState : int
{
    Separate,
    Intersection,
    Overlap,
};

/**
 * \brief Segment
 * \brief No basic operation
 * \tparam T
 */
class Segment
{
private:
    Point _first;
    Point _second;

public:
    // TODO: Ensure the segment is valid
    Segment() : _first(Point()), _second(Point()) {}
    Segment(Point const& first, Point const& second) : _first(first), _second(second) {}
    // copy-assignment -> call point copy-assignment
    // non-constructor

    inline Point first() const { return _first; }
    inline Point second() const { return _second; }
    inline bool  haveK(double const precision) const // Add precision
    {
        if (first().x() - second().x() < precision && first().x() - second().x() > -precision)
            return false; // *this // y
        else
            return true;
    }
    inline double k(double const precision) const // Add precision
    {
        if (!haveK(precision))
            return 0; // TODO: Warning
        else
        {
            return (second().y() - first().y()) / (second().x() - first().x());
        }
    }

    inline void setFirst(Point const& first) { _first = first; }
    inline void setSecond(Point const& second) { _second = second; }

    // assignment
    static bool isEqual(Segment const& a, Segment const& b, double const precision);    // Add precision
    static bool isNotEqual(Segment const& a, Segment const& b, double const precision); // Add precision

    /**
     * \brief [Cross test](https://blog.csdn.net/tengchongwei/article/details/72922056)
     */
    SegmentIntersectionState isIntersection(Segment const& other, double const precision) const; // Add precision
    /**
     * \brief [Similar triangle](https://blog.csdn.net/fengkeyleaf/article/details/117692109)
     */
    std::vector<Point> intersection(Segment const& other, double const precision) const; // Add precision
};

// typedef Segment      DoubleSegment;
// typedef Segment<int> IntSegment;

} // namespace geometry
} // namespace zong