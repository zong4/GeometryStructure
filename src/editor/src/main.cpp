/*! \mainpage Main page
# 简介
一些描述。
# Quick Start
一些使用说明。
*/

#include <iostream>
#include <vector>

#include "algorithm/boolean/sweep_line/SweepLine.h"
#include "common/log.h"
#include "geometry/Segment.h"

int main()
{
    zong::common::Log::init();
    zong::CLIENT_TRACE("123");
    zong::CLIENT_INFO("12");
    zong::CLIENT_WARN("1");
    zong::CLIENT_ERROR("12");
    zong::CLIENT_CRITICAL("123");

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
