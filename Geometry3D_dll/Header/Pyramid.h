#pragma once
#include <vector>
#include "Point.h"
#include "Shape.h"

class Pyramid {
private:
    double x, y, z; // base lower-left corner
    double base;    // base side length
    double height;  // along +z
public:
    Pyramid(double x, double y, double z, double base, double height);

    std::vector<Point> keyPoints() const; // 5 points (4 base + apex)
    Shape toShape() const;                // name: "Pyramid"
};

