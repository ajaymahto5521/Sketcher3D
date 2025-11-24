#include "Point.h" 
Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}
Point::~Point() = default; 

double Point::X() const { return x; } 
double Point::Y() const { return y; } 
double Point::Z() const { return z; }

void Point::setX(double v) { x = v; } 
void Point::setY(double v) { y = v; } 
void Point::setZ(double v) { z = v; }