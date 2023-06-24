#pragma once

#include <vector>

#include "../util/math.h"
#include "Point.h"

namespace zong
{
namespace geometry
{

/// <summary>
/// Separate: separate \n
/// Intersection: intersection \n
/// Overlap: overlap, not means two cross points, it also maybe one cross point \n
/// Unknown: the state is unknow, return this is because one segment is a point
/// </summary>
enum class SegmentIntersectionState : int
{
    Separate,
    Intersection,
    Overlap,
    Unknown,
};

/// <summary>
/// any segment, also can be a point(warning)
/// </summary>
class Segment
{
private:
    Point _first;
    Point _second;

public:
    // TODO: warning
    Segment() : _first(Point()), _second(Point()) {}

    Segment(Point const& first, Point const& second) : _first(first), _second(second) { isVaild(); }
    // copy-assignment -> call point copy-assignment
    // non-constructor

    inline Point first() const { return _first; }
    inline Point second() const { return _second; }

    /// <summary>
    /// if this segment is a point, it will warning
    /// </summary>
    /// <param name="precision">it will use util::HIGH_EPS if no precision in</param>
    /// <returns>true: a segment \n
    /// false: a point</returns>
    inline bool isVaild(double const precision = util::HIGH_EPS) const
    {
        return !Point::isEqual(_first, _second, precision); // TODO: warning
    }

    /// <summary>
    /// is this segment // y axis
    /// </summary>
    /// <param name="precision">precision</param>
    /// <returns>true: not // \n
    /// false: //</returns>
    inline bool haveK(double const precision) const
    {
        if (util::isEqual(first().x(), second().x(), precision))
            return false;
        else
            return true;
    }

    /// <summary>
    /// if no slope, it will warning, else return slope
    /// </summary>
    /// <param name="precision">precision</param>
    /// <returns>slope</returns>
    inline double k(double const precision) const
    {
        if (!haveK(precision))
            return 0.0; // TODO: Warning
        else
        {
            return (second().y() - first().y()) / (second().x() - first().x());
        }
    }

    inline void setFirst(Point const& first)
    {
        _first = first;
        isVaild();
    }

    inline void setSecond(Point const& second)
    {
        _second = second;
        isVaild();
    }

    // assignment
    static bool isEqual(Segment const& a, Segment const& b, double const precision);
    static bool isNotEqual(Segment const& a, Segment const& b, double const precision);

    /// <summary>
    /// use [cross test](https://blog.csdn.net/tengchongwei/article/details/72922056) to judge intersection state
    /// </summary>
    /// <param name="other">another segment</param>
    /// <param name="precision">precision</param>
    /// <returns>SegmentIntersectionState</returns>
    SegmentIntersectionState isIntersection(Segment const& other, double const precision) const;

    /// <summary>
    /// use [similar triangle](https://blog.csdn.net/fengkeyleaf/article/details/117692109) to get cross points
    /// </summary>
    /// <param name="other">another segment</param>
    /// <param name="precision">precision</param>
    /// <returns>cross points \n
    /// if return two points, they will sort by less x position and then less y position</returns>
    std::vector<Point> intersection(Segment const& other, double const precision) const; // Add precision
};

// typedef Segment      DoubleSegment;
// typedef Segment<int> IntSegment;

} // namespace geometry
} // namespace zong