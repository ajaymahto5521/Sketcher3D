#pragma once
#include <vector>
#include <string>
#include "Shape.h"

class Cuboid : public Shape {
private:
    Point origin;   // (x, y, z) at one corner (bottom-lower-left)
    double length;  // along +Y
    double width;   // along +X
    double height;  // along +Z
    std::vector<Point> vertices;

    void computeVertices();

public:
    Cuboid(double x, double y, double z, double length, double width, double height);
    ~Cuboid();

    const std::vector<Point>& getVertices() const override;

    double getLength() const;
    double getWidth() const;
    double getHeight() const;

    bool saveToDat(const std::string& filename) const override;
};

