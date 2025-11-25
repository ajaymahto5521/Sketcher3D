#pragma once
#include <string>
#include <vector>
#include "Point.h"

class Shape {
private:
    std::string name;
    std::vector<Point> points;
public:
    Shape();
    Shape(const std::string& name, const std::vector<Point>& pts);

    const std::string& Name()  const;
    const std::vector<Point>& Points() const;
    std::vector<Point>& Points();

    void setName(const std::string& n);
    void setPoints(const std::vector<Point>& pts);

    // Save "x y z" per line
    bool saveToDat(const std::string& filename) const;
};

// Holds many shapes and can write each to "<prefix>_<name>.dat"
class ShapeSet {
private:
    std::vector<Shape> items;
public:
    void add(const Shape& s);
    const std::vector<Shape>& all() const;
    bool saveAll(const std::string& prefix) const; // e.g., "out" -> out_Cube.dat, etc.
};

