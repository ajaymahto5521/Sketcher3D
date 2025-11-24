#pragma once
#include "Export.h"

class GEOMETRY3DDLL_API Point {
private:
	double x;
	double y;
	double z;
public:
	Point(double x, double y, double z);
	~Point();

	double X() const;
	double Y() const;
	double Z() const;

	void setX(double v);
	void setY(double v);
	void setZ(double v);
};