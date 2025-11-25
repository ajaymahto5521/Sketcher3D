#pragma once
#include <vector>
#include "Point.h"
#include "Shape.h"

class Cone {
private:
    double cx, cy, z; // base center at (cx,cy,z)
    double radius;
    double height;     // apex at z + height
    int steps;         // circle sampling
    int sideSamples;   // along the side (optional)
public:
    Cone(double cx, double cy, double z, double radius, double height,
        int steps = 36, int sideSamples = 5);

    std::vector<Point> cloud() const; // base circle + side samples
    Shape toShape() const;            // name: "Cone"
};

