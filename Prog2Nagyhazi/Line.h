#pragma once
#include "Coordinate.h"
#include "Circle.h"
#include "Parabola.h"
#include "Intersections.h"
#include <cmath>
#include <string>

class Line: public Intersection{
	Coordinate point1;
	Coordinate point2;
public:
	Line();
	Line(Coordinate, Coordinate);
	Coordinate nVector();

	Coordinate getPoint1()const;
	Coordinate getPoint2()const;
	void setPoint1(double, double);
	void setPoint2(double, double);

	Coordinate* LineIntersection(Line&)override;
	Coordinate* CircleIntersection(Circle&)override;
	Coordinate* ParabolaIntersection(Parabola&)override;
};