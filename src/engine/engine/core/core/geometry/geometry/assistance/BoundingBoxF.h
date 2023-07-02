#pragma once

#include <float.h>

#include "../PointF.h"

namespace zong
{

/**
 * \brief _data0,1 mean minPoint(left and bottom), _data2,3 mean maxPoint(right and top)
 */
class BoundingBoxF
{
private:
    double _data[4];

public:
    BoundingBoxF()
    {
        _data[0] = DBL_MAX;
        _data[1] = DBL_MAX;
        _data[2] = -DBL_MAX;
        _data[3] = -DBL_MAX;
    }

    inline double minX() const { return _data[0]; }
    inline double minY() const { return _data[1]; }
    inline double maxX() const { return _data[2]; }
    inline double maxY() const { return _data[3]; }

    inline PointF minPoint() const { return PointF(_data[0], _data[1]); }
    inline PointF maxPoint() const { return PointF(_data[2], _data[3]); }

    void extend(PointF const& point);
    void extend(BoundingBoxF const& box);

    bool isIntersection(BoundingBoxF const& box, double precision) const;

private:
    inline void setMinX(double minX) { _data[0] = minX; }
    inline void setMinY(double minY) { _data[1] = minY; }
    inline void setMaxX(double maxX) { _data[2] = maxX; }
    inline void setMaxY(double maxY) { _data[3] = maxY; }
};

} // namespace zong