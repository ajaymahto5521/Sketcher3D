#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Point.h"
#include "Cuboid.h"

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

    file.close();
    return true;
}

int main() {
    try {
        // A cube: origin (0,0,0), side = 10
        Cuboid cube(0.0, 0.0, 0.0, 10.0, 10.0, 10.0);

        // A cuboid: origin (20,5,0), L (Y) = 15, W (X) = 25, H (Z) = 8
        Cuboid cuboid(20.0, 5.0, 0.0, 15.0, 25.0, 8.0);

        const std::string cubeFile = "cube_edges.dat";
        const std::string cuboidFile = "cuboid_edges.dat";

        bool ok1 = writeEdges18(cube, cubeFile);
        bool ok2 = writeEdges18(cuboid, cuboidFile);

        if (ok1 && ok2) {
            std::cout << "Wrote 18 points to " << cubeFile
                << " and " << cuboidFile << " successfully.\n";
            return 0;
        }
        else {
            std::cerr << "Failed to write one or more files.\n";
            return 1;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 1;
    }
}
