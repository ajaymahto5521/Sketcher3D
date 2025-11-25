#include "Shape.h"
#include <fstream>

Shape::Shape() {}
Shape::Shape(const std::string& name_, const std::vector<Point>& pts)
    : name(name_), points(pts) {
}

const std::string& Shape::Name() const { return name; }
const std::vector<Point>& Shape::Points() const { return points; }
std::vector<Point>& Shape::Points() { return points; }

void Shape::setName(const std::string& n) { name = n; }
void Shape::setPoints(const std::vector<Point>& pts) { points = pts; }

bool Shape::saveToDat(const std::string& filename) const {
    std::ofstream out(filename.c_str());
    if (!out) return false;
    for (const auto& p : points) {
        out << p.X() << " " << p.Y() << " " << p.Z() << "\n";
    }
    return true;
}

void ShapeSet::add(const Shape& s) { items.push_back(s); }
const std::vector<Shape>& ShapeSet::all() const { return items; }

bool ShapeSet::saveAll(const std::string& prefix) const {
    bool ok = true;
    for (const auto& s : items) {
        std::string fname = prefix + "_" + s.Name() + ".dat";
        if (!s.saveToDat(fname)) ok = false;
    }
    return ok;
}
