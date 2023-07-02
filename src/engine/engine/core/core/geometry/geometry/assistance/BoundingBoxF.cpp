#include "BoundingBoxF.h"

void zong::BoundingBoxF::extend(PointF const& point)
{
    setMinX(minX() < point.x() ? minX() : point.x());
    setMaxX(maxX() > point.x() ? maxX() : point.x());
    setMinY(minY() < point.y() ? minY() : point.y());
    setMaxY(maxY() > point.y() ? maxY() : point.y());
}

void zong::BoundingBoxF::extend(BoundingBoxF const& box)
{
    setMinX(minX() < box.minX() ? minX() : box.minX());
    setMaxX(maxX() > box.maxX() ? maxX() : box.maxX());
    setMinY(minY() < box.minY() ? minY() : box.minY());
    setMaxY(maxY() > box.maxY() ? maxY() : box.maxY());
}

bool zong::BoundingBoxF::isIntersection(BoundingBoxF const& box, double precision) const
{
    if (util::isGreater(this->minX(), box.maxX(), precision) || util::isGreater(box.minX(), this->maxX(), precision) ||
        util::isGreater(this->minY(), box.maxY(), precision) || util::isGreater(box.minY(), this->maxY(), precision))
        return false;
    else
        return true;
}
