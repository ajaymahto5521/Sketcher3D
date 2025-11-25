#pragma once
#include <vector>
#include "Shape.h"

class Cube : public Shape {
private:
    Point origin;
    double side;
    std::vector<Point> vertices;

    void computeVertices();

public:
    Cube(double x, double y, double z, double side);
    const std::vector<Point>& getVertices() const override;
};
