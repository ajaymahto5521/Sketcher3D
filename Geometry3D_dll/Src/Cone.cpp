#include "Cone.h"
#include <cmath>

Cone::Cone(double cx_, double cy_, double z_, double radius_, double height_, int steps_, int sideSamples_)
    : cx(cx_), cy(cy_), z(z_), radius(radius_), height(height_),
    steps(steps_), sideSamples(sideSamples_) {
}

std::vector<Point> Cone::cloud() const {
    std::vector<Point> pts;
    if (steps < 3) return pts;

    // Base circle
    for (int i = 0; i < steps; ++i) {
        double ang = (2.0 * M_PI * i) / steps;
        double x = cx + radius * std::cos(ang);
        double y = cy + radius * std::sin(ang);
        pts.push_back(Point(x, y, z));
    }

    // Apex
    Point apex(cx, cy, z + height);

    // Side "meridians" from base rim up to apex
    if (sideSamples < 1) sideSamples = 1;
    for (int i = 0; i < steps; ++i) {
        double ang = (2.0 * M_PI * i) / steps;
        double bx = cx + radius * std::cos(ang);
        double by = cy + radius * std::sin(ang);
        for (int s = 1; s <= sideSamples; ++s) {
            double t = double(s) / double(sideSamples);
            double x = bx + (apex.X() - bx) * t;
            double y = by + (apex.Y() - by) * t;
            double zz = z + (apex.Z() - z) * t;
            pts.push_back(Point(x, y, zz));
        }
    }

    return pts;
}

Shape Cone::toShape() const {
    return Shape("Cone", cloud());
}
