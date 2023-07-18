#pragma once
#include "Coordinate.h"
#include "Line.h"
#include "Parabola.h"
#include "Intersections.h"
#include <cmath>
#include <string>

class Circle: public Intersection {
	Coordinate centerpoint;
	double range;
public:
	Circle();
	Circle(Coordinate, double);
	

	Coordinate getCenterpoint()const;
	double getRange()const;
	void setCenterpoint(double, double);
	void setRange(double);

	Coordinate* LineIntersection(Line&);
	Coordinate* CircleIntersection(Circle&);
	Coordinate* ParabolaIntersection(Parabola&);
};