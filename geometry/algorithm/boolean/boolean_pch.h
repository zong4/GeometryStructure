#pragma once

#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

#include "../../geometry/PointF.h"
#include "../../geometry/SegmentF.h"

// 浮点精度
constexpr double EPS       = 0.0000001;
constexpr double SMALL_EPS = 0.00000001;
#define IS_FLOAT_EQUAL(a, b) ((((a) - (b)) < EPS) && (((b) - (a)) < EPS))

struct Point2dHash
{
    size_t operator()(zong::PointF const& point2d) const // size_t
    {
        // return size_t(l.k ^ l.b);//自定义哈希
        return std::hash<double>()(point2d.x()) ^ std::hash<double>()(point2d.y());
    }
};

struct Point2dIsEqual
{
    bool operator()(zong::PointF const& firstPoint2d,
                    zong::PointF const& secondPoint2d) const // 最后的const不能少
    {
        return (IS_FLOAT_EQUAL(firstPoint2d.x(), secondPoint2d.x()) && IS_FLOAT_EQUAL(firstPoint2d.y(), secondPoint2d.y()));
    }
};

typedef std::unordered_set<zong::PointF, Point2dHash, Point2dIsEqual> point2d_unordered_set;