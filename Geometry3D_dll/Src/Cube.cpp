#include "Cube.h"

Cube::Cube(double x, double y, double z, double side)
    : origin(x, y, z), side(side) {
    computeVertices();
}

void Cube::computeVertices() {
    vertices.clear();
    vertices.reserve(8);

    double x = origin.X();
    double y = origin.Y();
    double z = origin.Z();

    // Bottom square
    vertices.push_back(Point(x, y, z));
    vertices.push_back(Point(x + side, y, z));
    vertices.push_back(Point(x + side, y + side, z));
    vertices.push_back(Point(x, y + side, z));

    // Top square
    vertices.push_back(Point(x, y, z + side));
    vertices.push_back(Point(x + side, y, z + side));
    vertices.push_back(Point(x + side, y + side, z + side));
    vertices.push_back(Point(x, y + side, z + side));
}

const std::vector<Point>& Cube::getVertices() const {
    return vertices;
}
