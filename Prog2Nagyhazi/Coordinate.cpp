#include "Coordinate.h"

Coordinate::Coordinate() : x(0), y(0) {}
Coordinate::Coordinate(double a, double b) : x(a), y(b) {}

double Coordinate::getX()const {
	return x;
}

double Coordinate::getY()const {
	return y;
}

void Coordinate::setX(double a) {
	x = a;
}

void Coordinate::setY(double b) {
	y = b;
}

std::ostream& operator<<(std::ostream& os, const Coordinate& other) {
	os << "(" << other.x << "; " << other.y << ")";
	return os;
}