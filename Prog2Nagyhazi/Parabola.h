#pragma once
#include "Coordinate.h"
#include "Circle.h"
#include "Line.h"
#include "Intersections.h"
#include <cmath>
#include <string>

class Parabola: public Intersection {
	double p;
	Coordinate z;
public:
	Parabola();
	Parabola(double, Coordinate);

	double getP()const;
	Coordinate getz()const;
	void setP(double);
	void setZ(double, double);

	Coordinate* LineIntersection(Line&);
	Coordinate* CircleIntersection(Circle&);
	Coordinate* ParabolaIntersection(Parabola&);
};