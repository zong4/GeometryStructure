#include <iostream>

#include "geometry/Point.h"

int main(int argc, char** argv)
{
    zong::geometry::Point const point(2, 1);
    std::cout << point.x() << std::endl;
    return 0;
}
