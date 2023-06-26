#include "Segment.h"

#include <algorithm>

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
    if (!isVaild(precision))
    {
        // TODO: warning
        return SegmentIntersectionState::Unknown;
    }

    // TODO: add box class
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

    // sorry, can't give suitable name
    double const a1 = thisNomVec.cross(Vector((other.first() - this->second()).normalize()));
    double const a2 = thisNomVec.cross(Vector((other.second() - this->second()).normalize()));
    double const b1 = otherNomVec.cross(Vector((this->first() - other.second()).normalize()));
    double const b2 = otherNomVec.cross(Vector((this->second() - other.second()).normalize()));
    if (util::isGreater(a1 * a2, 0.0, precision) || util::isGreater(b1 * b2, 0.0, precision))
        return SegmentIntersectionState::Separate;
    else if (util::isLess(a1 * a2, 0.0, precision) || util::isLess(b1 * b2, 0.0, precision))
        return SegmentIntersectionState::Intersection;

    return SegmentIntersectionState::Overlap;
}

std::vector<Point> Segment::intersection(Segment const& other, double const precision) const
{
    SegmentIntersectionState const state = this->isIntersection(other, precision);
    if (state == SegmentIntersectionState::Unknown || state == SegmentIntersectionState::Separate)
        return {};

    if (state == SegmentIntersectionState::Overlap)
    {
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

        if (Point::isEqual(points[1], points[2], precision))
            return {(points[1] + points[2]) * 0.5}; // TODO: * 0.5 is meaningful?
        else
        {
            std::vector<Point> crossPoints(2);
            if (Point::isEqual(points[0], points[1], precision))
                crossPoints[0] = ((points[0] + points[1]) * 0.5); // TODO: * 0.5 is meaningful?
            else
                crossPoints[0] = (points[1]);

            if (Point::isEqual(points[2], points[3], precision))
                crossPoints[1] = ((points[2] + points[3]) * 0.5); // TODO: * 0.5 is meaningful?
            else
                crossPoints[1] = (points[2]);

            return crossPoints;
        }
    }
    else // intersection
    {
        Vector const base           = this->first() - this->second();
        double const firstDistance  = fabs(base.cross(other.first() - this->second()));
        double const secondDistance = fabs(base.cross(other.second() - this->second()));

        double const secondDistancePercent = secondDistance / (firstDistance + secondDistance);

        // TODO: if secondDistancePercent == 0.0 or secondDistancePercent == 1.0, shall return end point?
        return {other.second() * (1.0 - secondDistancePercent) + other.first() * secondDistancePercent};
    }
}

} // namespace geometry
} // namespace zong
