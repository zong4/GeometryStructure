
#include <iostream>
#include <vector>

#include "algorithm/boolean/sweep_line/SweepLine.h"
#include "geometry/Segment.h"
#include "geometry/assistance/Vector.h"

int main()
{
    std::vector<zong::geometry::Segment> segments;
    segments.emplace_back(zong::geometry::Segment(zong::geometry::Point(0.0, 0.0), zong::geometry::Point(2.0, 2.0)));
    segments.emplace_back(zong::geometry::Segment(zong::geometry::Point(2.0, 0.0), zong::geometry::Point(0.0, 2.0)));

    SweepLine sweepLine(segments);
    sweepLine.scan();
    point2d_unordered_set const points = sweepLine.GetAllCrossPoints();

    for (zong::geometry::Point const& point : points)
    {
        std::cout << "x: " << point.x() << ", y: " << point.y() << std::endl;
    }

    return 0;
}
