#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Point.h"

class Cube {
private:
    Point origin;
    double side;
    std::vector<Point> vertices;

    void computeVertices();

public:
    Cube(double x, double y, double z, double side);

    const std::vector<Point>& getVertices() const;
    bool saveToDat(const std::string& filename) const;
};
