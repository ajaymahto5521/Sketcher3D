#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Point.h"
#include "Shape.h"
#include "Cube.h"
#include "Cuboid.h"
#include "Pyramid.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cone.h"

// Writes 18 points: bottom loop (5), top loop (5), 4 verticals (8)
bool writeEdges18(const Cuboid& c, const std::string& filename) {
    const std::vector<Point>& v = c.getVertices();
    if (v.size() != 8) {
        std::cerr << "Error: Cuboid does not have 8 vertices.\n";
        return false;
    }

    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file: " << filename << "\n";
        return false;
    }

    auto emit = [&](int idx) {
        file << v[idx].X() << " " << v[idx].Y() << " " << v[idx].Z() << "\n";
        };

    // Bottom face loop: 0 -> 1 -> 2 -> 3 -> 0  (5 points)
    emit(0); emit(1); emit(2); emit(3); emit(0);
    file << "\n";

    // Top face loop: 4 -> 5 -> 6 -> 7 -> 4  (5 points)
    emit(4); emit(5); emit(6); emit(7); emit(4);
    file << "\n";

    // Vertical edges: (0-4), (1-5), (2-6), (3-7)  (8 points total)
    emit(0); emit(4);
    emit(1); emit(5);
    emit(2); emit(6);
    emit(3); emit(7);

    return true;
}

int main() {
    try {
        // Cube & Cuboid
        Cuboid cube(0.0, 0.0, 0.0, 10.0, 10.0, 10.0);
        Cuboid cuboid(20.0, 5.0, 0.0, 15.0, 25.0, 8.0);

        // Other shapes
        Pyramid pyramid(50.0, 0.0, 0.0, 20.0, 20.0, 15.0);       // base 20x20, height 15
        Sphere sphere(0.0, 40.0, 0.0, 8.0, 16, 24);             // center at (0,40,0)
        Cylinder cylinder(40.0, 40.0, 0.0, 6.0, 15.0, 32, 4);   // stacks=4 rings
        Cone cone(80.0, 0.0, 0.0, 8.0, 18.0, 32, 3);            // stacks=3 rings

        // Save simple vertex clouds (x y z per line)
        if (!cube.saveToDat("cube_vertices.dat"))       std::cerr << "Failed: cube_vertices.dat\n";
        if (!cuboid.saveToDat("cuboid_vertices.dat"))   std::cerr << "Failed: cuboid_vertices.dat\n";
        if (!pyramid.saveToDat("pyramid_vertices.dat")) std::cerr << "Failed: pyramid_vertices.dat\n";
        if (!sphere.saveToDat("sphere_vertices.dat"))   std::cerr << "Failed: sphere_vertices.dat\n";
        if (!cylinder.saveToDat("cylinder_vertices.dat")) std::cerr << "Failed: cylinder_vertices.dat\n";
        if (!cone.saveToDat("cone_vertices.dat"))       std::cerr << "Failed: cone_vertices.dat\n";

        // Optional: edge file with 18 points for cube & cuboid (good for gnuplot line plotting)
        bool ok1 = writeEdges18(cube, "cube_edges.dat");
        bool ok2 = writeEdges18(cuboid, "cuboid_edges.dat");

        if (ok1 && ok2) {
            std::cout << "Wrote vertex clouds and edge files successfully.\n";
            return 0;
        }
        else {
            std::cerr << "Completed with some errors writing edge files.\n";
            return 1;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 1;
    }
}
