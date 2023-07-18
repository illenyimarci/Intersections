#pragma once
#include "Coordinate.h"
#include "Circle.h"
#include "Parabola.h"
#include "Line.h"

class Line;
class Circle;
class Parabola;

class Intersection {
public:
	virtual Coordinate* LineIntersection(Line&) = 0;
	virtual Coordinate* CircleIntersection(Circle&) = 0;
	virtual Coordinate* ParabolaIntersection(Parabola&) = 0;
};