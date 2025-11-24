#pragma once 
#include "Export.h" 
#include "Point.h" 
#include <vector> 
#include <string> 
#include <fstream> 
class GEOMETRY3DDLL_API Cuboid { 
private: 
	Point origin; // starting point (x, y, z) 
	double length; // along Y 
	double width; // along X 
	double height;// along Z 
	std::vector<Point> vertices; // stores 8 points 
	void computeVertices(); // internal helper 
public: 
	Cuboid(double x, double y, double z, double length, double width, double height);
	~Cuboid(); const std::vector<Point>& getVertices() const;
	double getLength() const; 
	double getWidth() const; 
	double getHeight() const; 
	bool saveToDat(const std::string& filename) const; 
};
