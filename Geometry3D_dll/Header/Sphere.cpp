#include "Sphere.h"
#include <cmath>

Sphere::Sphere(double cx_, double cy_, double cz_, double r_, int stacks_, int slices_)
    : cx(cx_), cy(cy_), cz(cz_), r(r_), stacks(stacks_), slices(slices_) {
}

std::vector<Point> Sphere::cloud() const {
    std::vector<Point> pts;
    if (stacks < 2 || slices < 3) return pts;

    // theta: 0..pi (latitude), phi: 0..2pi (longitude)
    for (int i = 0; i <= stacks; ++i) {
        double theta = M_PI * double(i) / double(stacks);      // 0..pi
        double st = std::sin(theta);
        double ct = std::cos(theta);
        for (int j = 0; j < slices; ++j) {
            double phi = 2.0 * M_PI * double(j) / double(slices); // 0..2pi
            double sp = std::sin(phi);
            double cp = std::cos(phi);

            double x = cx + r * st * cp;
            double y = cy + r * st * sp;
            double z = cz + r * ct;
            pts.push_back(Point(x, y, z));
        }
    }
    return pts;
}

Shape Sphere::toShape() const {
    return Shape("Sphere", cloud());
}
