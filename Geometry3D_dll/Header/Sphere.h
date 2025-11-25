#pragma once
#include <vector>
#include "Point.h"
#include "Shape.h"

class Sphere {
private:
    double cx, cy, cz; // center
    double r;
    int stacks;        // latitude samples (>=2)
    int slices;        // longitude samples (>=3)
public:
    Sphere(double cx, double cy, double cz, double r, int stacks = 12, int slices = 24);

    std::vector<Point> cloud() const; // sampled surface
    Shape toShape() const;            // name: "Sphere"
};

