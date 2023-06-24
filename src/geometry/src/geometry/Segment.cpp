#include "Segment.h"

#include <algorithm>

#include "../util/math.h"
#include "assistance/Vector.h"

namespace zong
{
namespace geometry
{

bool Segment::isEqual(Segment const& a, Segment const& b, double const precision)
{
    return Point::isEqual(a.first(), b.first(), precision) && Point::isEqual(a.second(), b.second(), precision);
}

bool Segment::isNotEqual(Segment const& a, Segment const& b, double const precision)
{
    return !Segment::isEqual(a, b, precision);
}

SegmentIntersectionState Segment::isIntersection(Segment const& other, double const precision) const
{
    // box intersection
    if ((std::min(other.first().x(), other.second().x()) - std::max(this->first().x(), this->second().x())) > precision ||
        (std::min(this->first().x(), this->second().x()) - std::max(other.first().x(), other.second().x())) > precision ||
        (std::min(other.first().y(), other.second().y()) - std::max(this->first().y(), this->second().y())) > precision ||
        (std::min(this->first().y(), this->second().y()) - std::max(other.first().y(), other.second().y())) > precision)
    {
        return SegmentIntersectionState::Separate;
    }

    // cross test
    Vector const thisNomVec((this->first() - this->second()).normalize());
    Vector const otherNomVec((other.first() - other.second()).normalize());

    // zong need change, if cross answer is 0, can't normalize
    // sorry, can't give suitable name
    double const a1 = thisNomVec.cross(Vector((other.first() - this->second()).normalize()));
    double const a2 = thisNomVec.cross(Vector((other.second() - this->second()).normalize()));
    double const b1 = otherNomVec.cross(Vector((this->first() - other.second()).normalize()));
    double const b2 = otherNomVec.cross(Vector((this->second() - other.second()).normalize()));
    if (a1 * a2 >= precision || b1 * b2 >= precision)
        return SegmentIntersectionState::Separate;
    else if (a1 * a2 <= -precision || b1 * b2 <= -precision)
        return SegmentIntersectionState::Intersection;

    return SegmentIntersectionState::Overlap;
}

std::vector<Point> Segment::intersection(Segment const& other, double const precision) const
{
    SegmentIntersectionState const state = this->isIntersection(other, precision);
    if (state == SegmentIntersectionState::Separate)
        return {};

    if (state == SegmentIntersectionState::Overlap)
    {
        std::vector<Point> crossPoints(0);

        std::vector<Point> points(4);
        points[0] = this->first();
        points[1] = this->second();
        points[2] = other.first();
        points[3] = other.second();

        std::sort(points.begin(), points.end(), [&](Point const& a, Point const& b) {
            if (util::isNotEqual(a.x(), b.x(), precision))
                return a.x() < b.x();
            else
                return a.y() < b.y();
        });

        if (Point::isEqual(points[0], points[1], precision))
        {
            crossPoints.emplace_back(points[0] + points[1]);
        }
    }

    // intersection
    {
        Vector const base           = this->first() - this->second();
        double const firstDistance  = fabs(base.cross(other.first() - this->second()));
        double const secondDistance = fabs(base.cross(other.second() - this->second()));

        double const secondDistancePercent = secondDistance / (firstDistance + secondDistance);

        // zong if secondDistancePercent == 0.0 or secondDistancePercent == 1.0

        return {other.second() * (1.0 - secondDistancePercent) + other.first() * secondDistancePercent};
    }
}

} // namespace geometry
} // namespace zong
