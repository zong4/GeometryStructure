#include "SegmentF.h"

#include <algorithm>

#include "../../log/Log.h"

bool zong::SegmentF::haveK(double const precision) const
{
    if (util::isEqual(first().x(), second().x(), precision))
        return false;
    else
        return true;
}

double zong::SegmentF::k(double const precision) const
{
    if (!haveK(precision))
    {
        ZONG_CORE_WARN("no slope, you should call haveK firstly");
        return 0.0;
    }
    else
        return (second().y() - first().y()) / (second().x() - first().x());
}

zong::BoundingBoxF zong::SegmentF::box() const
{
    BoundingBoxF box;

    box.extend(this->first());
    box.extend(this->second());

    return box;
}

bool zong::SegmentF::isEqual(SegmentF const& a, SegmentF const& b, double const precision)
{
    return PointF::isEqual(a.first(), b.first(), precision) && PointF::isEqual(a.second(), b.second(), precision);
}

bool zong::SegmentF::isNotEqual(SegmentF const& a, SegmentF const& b, double const precision)
{
    return !SegmentF::isEqual(a, b, precision);
}

zong::SegmentIntersectionState zong::SegmentF::isIntersection(SegmentF const& other, double const precision) const
{
    // box intersection
    if (!this->box().isIntersection(other.box(), precision))
        return SegmentIntersectionState::Separate;

    // cross test
    VectorF const thisNomVec  = (this->first() - this->second()).normalize(precision);
    VectorF const otherNomVec = (other.first() - other.second()).normalize(precision);

    // sorry, can't give suitable name
    double const a1 = thisNomVec.cross((other.first() - this->second()).normalize(precision));
    double const a2 = thisNomVec.cross((other.second() - this->second()).normalize(precision));
    double const b1 = otherNomVec.cross((this->first() - other.second()).normalize(precision));
    double const b2 = otherNomVec.cross((this->second() - other.second()).normalize(precision));

    if (util::isGreater(a1 * a2, 0.0, precision) || util::isGreater(b1 * b2, 0.0, precision))
        return SegmentIntersectionState::Separate;
    else if (util::isLess(a1 * a2, 0.0, precision) || util::isLess(b1 * b2, 0.0, precision))
        return SegmentIntersectionState::Intersection;

    return SegmentIntersectionState::Overlap;
}

std::vector<zong::PointF> zong::SegmentF::intersection(SegmentF const& other, double const precision) const
{
    SegmentIntersectionState const state = this->isIntersection(other, precision);
    if (state == SegmentIntersectionState::Separate)
        return {};

    if (state == SegmentIntersectionState::Overlap)
    {
        std::vector<PointF> points(4);
        points[0] = this->first();
        points[1] = this->second();
        points[2] = other.first();
        points[3] = other.second();

        std::sort(points.begin(), points.end(), [&](PointF const& a, PointF const& b) {
            if (util::isNotEqual(a.x(), b.x(), precision))
                return a.x() < b.x();
            else
                return a.y() < b.y();
        });

        if (PointF::isEqual(points[1], points[2], precision))
            return {(points[1] + points[2]) * 0.5}; // TODO: * 0.5 is meaningful?
        else
        {
            std::vector<PointF> crossPoints(2);
            if (PointF::isEqual(points[0], points[1], precision))
                crossPoints[0] = ((points[0] + points[1]) * 0.5); // TODO: * 0.5 is meaningful?
            else
                crossPoints[0] = (points[1]);

            if (PointF::isEqual(points[2], points[3], precision))
                crossPoints[1] = ((points[2] + points[3]) * 0.5); // TODO: * 0.5 is meaningful?
            else
                crossPoints[1] = (points[2]);

            if (PointF::isEqual(crossPoints[0], crossPoints[1], precision))
                return {(points[2] + points[3]) * 0.5}; // TODO: * 0.5 is meaningful?
            else
                return crossPoints;
        }
    }
    else // intersection
    {
        VectorF const base           = this->first() - this->second();
        double const  firstDistance  = fabs(base.cross(other.first() - this->second()));
        double const  secondDistance = fabs(base.cross(other.second() - this->second()));

        double const secondDistancePercent = secondDistance / (firstDistance + secondDistance);

        // TODO: if secondDistancePercent == 0.0 or secondDistancePercent == 1.0, shall return end point?
        return {other.second() * (1.0 - secondDistancePercent) + other.first() * secondDistancePercent};
    }
}

inline bool zong::SegmentF::isValid(double const precision) const
{
    if (PointF::isEqual(_first, _second, precision))
    {
        ZONG_CORE_WARN("this segment is just a point under the precision");
        return false;
    }
    return true;
}
