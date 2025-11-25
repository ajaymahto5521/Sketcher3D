#include "Pyramid.h"

Pyramid::Pyramid(double x_, double y_, double z_, double base_, double height_)
    : x(x_), y(y_), z(z_), base(base_), height(height_) {
}

std::vector<Point> Pyramid::keyPoints() const {
    std::vector<Point> v;
    v.reserve(5);

    // base corners on plane z
    v.push_back(Point(x, y, z));
    v.push_back(Point(x + base, y, z));
    v.push_back(Point(x + base, y + base, z));
    v.push_back(Point(x, y + base, z));

    // apex centered above base
    double cx = x + base * 0.5;
    double cy = y + base * 0.5;
    v.push_back(Point(cx, cy, z + height));
    return v;
}

Shape Pyramid::toShape() const {
    return Shape("Pyramid", keyPoints());
}
