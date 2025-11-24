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
    vertices.emplace_back(x, y, z);
    vertices.emplace_back(x + side, y, z);
    vertices.emplace_back(x + side, y + side, z);
    vertices.emplace_back(x, y + side, z);

    // Top square
    vertices.emplace_back(x, y, z + side);
    vertices.emplace_back(x + side, y, z + side);
    vertices.emplace_back(x + side, y + side, z + side);
    vertices.emplace_back(x, y + side, z + side);
}

const std::vector<Point>& Cube::getVertices() const {
    return vertices;
}

bool Cube::saveToDat(const std::string& filename) const {
    std::ofstream f(filename);
    if (!f.is_open()) return false;

    for (auto& p : vertices)
        f << p.X() << " " << p.Y() << " " << p.Z() << "\n";

    return true;
}
