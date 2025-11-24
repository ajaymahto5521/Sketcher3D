#include <iostream>
#include <fstream>
#include "Point.h"
#include "Cuboid.h"

int main() {
    // Create a cuboid with origin (0,0,0), length=5 (Y), width=4 (X), height=3 (Z)
    Cuboid box(0.0, 0.0, 0.0, 5.0, 4.0, 3.0);

    // (Optional) still dump raw 8 vertices if you like
    box.saveToDat("cuboid.dat");

    // Now write edges as 18 points for gnuplot (with blank lines between segments)
    const auto& V = box.getVertices(); // indices: 0..3 bottom, 4..7 top (as per your Cuboid::computeVertices)

    std::ofstream f("cuboid.dat");
    if (!f.is_open()) {
        std::cerr << "Failed to open cuboid.dat\n";
        return 1;
    }

    auto write = [&](int i) {
        const auto& p = V[i];
        f << p.X() << " " << p.Y() << " " << p.Z() << "\n";
        };

    // Bottom loop (5 points, closing)
    write(0); write(1); write(2); write(3); write(0);
    f << "\n\n";

    // Top loop (5 points, closing)
    write(4); write(5); write(6); write(7); write(4);
    f << "\n\n";

    // Vertical edges (4 segments, 2 points each)
    write(0); write(4); f << "\n\n";
    write(1); write(5); f << "\n\n";
    write(2); write(6); f << "\n\n";
    write(3); write(7); f << "\n";

    f.close();

    std::cout << "Generated cuboid.dat with 18 points for gnuplot.\n";
    return 0;
}
