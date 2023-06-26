#pragma once

#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

#include "../../geometry/Point.h"
#include "../../geometry/Segment.h"

// 暂时用不到
enum class Axis : int
{
    X = 0,
    Y = 1,
};

// 浮点精度
constexpr double EPS       = 0.0000001;
constexpr double SMALL_EPS = 0.00000001;
#define IS_FLOAT_EQUAL(a, b) ((((a) - (b)) < EPS) && (((b) - (a)) < EPS))

#pragma region 存交点的容器

struct Point2dHash
{
    size_t operator()(zong::geometry::Point const& point2d) const // size_t
    {
        // return size_t(l.k ^ l.b);//自定义哈希
        return std::hash<double>()(point2d.x()) ^ std::hash<double>()(point2d.y());
    }
};

struct Point2dIsEqual
{
    bool operator()(zong::geometry::Point const& firstPoint2d, zong::geometry::Point const& secondPoint2d) const // 最后的const不能少
    {
        return (IS_FLOAT_EQUAL(firstPoint2d.x(), secondPoint2d.x()) && IS_FLOAT_EQUAL(firstPoint2d.y(), secondPoint2d.y()));
    }
};

typedef std::unordered_set<zong::geometry::Point, Point2dHash, Point2dIsEqual> point2d_unordered_set;

#pragma endregion
