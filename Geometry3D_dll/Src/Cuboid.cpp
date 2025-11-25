#include "Cuboid.h"
#include <fstream>
#include <iostream>

Cuboid::Cuboid(double x, double y, double z, double length, double width, double height)
    : origin(x, y, z), length(length), width(width), height(height) {
    computeVertices();
}

Cuboid::~Cuboid() = default;

void Cuboid::computeVertices() {
    vertices.clear();
    vertices.reserve(8);

    double x = origin.X();
    double y = origin.Y();
    double z = origin.Z();

    // Bottom face (z)
    vertices.push_back(Point(x, y, z));
    vertices.push_back(Point(x + width, y, z));
    vertices.push_back(Point(x + width, y + length, z));
    vertices.push_back(Point(x, y + length, z));

    // Top face (z + height)
    vertices.push_back(Point(x, y, z + height));
    vertices.push_back(Point(x + width, y, z + height));
    vertices.push_back(Point(x + width, y + length, z + height));
    vertices.push_back(Point(x, y + length, z + height));
}

const std::vector<Point>& Cuboid::getVertices() const {
    return vertices;
}

double Cuboid::getLength() const { return length; }
double Cuboid::getWidth()  const { return width; }
double Cuboid::getHeight() const { return height; }

bool Cuboid::saveToDat(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file: " << filename << "\n";
        return false;
    }
    for (const auto& v : vertices) {
        file << v.X() << " " << v.Y() << " " << v.Z() << "\n";
    }
    return true;
}
