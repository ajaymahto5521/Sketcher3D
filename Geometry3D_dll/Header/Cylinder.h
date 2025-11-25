#pragma once
#include <vector>
#include "Point.h"
#include "Shape.h"

class Cylinder {
protected:

private:
    double cx, cy, z; // center of base circle at (cx,cy,z)
    double radius;
    double height;     // along +z
    int steps;         // circle sampling
    int zSlices;       // vertical sampling
public:
    Cylinder(double cx, double cy, double z, double radius, double height,
        int steps = 36, int zSlices = 5);

    std::vector<Point> cloud() const; // sampled rings
    Shape toShape() const;            // name: "Cylinder"
};

