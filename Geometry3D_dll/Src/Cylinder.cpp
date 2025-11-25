#include "Cylinder.h"
#include <cmath>

Cylinder::Cylinder(double cx_, double cy_, double z_, double radius_, double height_, int steps_, int zSlices_)
    : cx(cx_), cy(cy_), z(z_), radius(radius_), height(height_), steps(steps_), zSlices(zSlices_) {
}

std::vector<Point> Cylinder::cloud() const {
    std::vector<Point> pts;
    if (steps < 3) return pts;
    if (zSlices < 1) return pts;

    pts.reserve(steps * (zSlices + 1) + steps * 2);

    // bottom and top rim
    for (int i = 0; i < steps; ++i) {
        double ang = (2.0 * M_PI * i) / steps;
        double x = cx + radius * std::cos(ang);
        double y = cy + radius * std::sin(ang);
        pts.push_back(Point(x, y, z));             // bottom rim
    }
    for (int i = 0; i < steps; ++i) {
        double ang = (2.0 * M_PI * i) / steps;
        double x = cx + radius * std::cos(ang);
        double y = cy + radius * std::sin(ang);
        pts.push_back(Point(x, y, z + height));    // top rim
    }

    // side surface rings between bottom and top
    for (int s = 1; s < zSlices; ++s) {
        double zz = z + height * (double(s) / double(zSlices));
        for (int i = 0; i < steps; ++i) {
            double ang = (2.0 * M_PI * i) / steps;
            double x = cx + radius * std::cos(ang);
            double y = cy + radius * std::sin(ang);
            pts.push_back(Point(x, y, zz));
        }
    }

    return pts;
}

Shape Cylinder::toShape() const {
    return Shape("Cylinder", cloud());
}
