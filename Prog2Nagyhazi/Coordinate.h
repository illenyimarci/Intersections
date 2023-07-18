#pragma once
#include <iostream>

class Coordinate {
	double x;
	double y;

	friend std::ostream& operator<<(std::ostream&, const Coordinate&);
public:
	Coordinate();
	Coordinate(double, double);

	double getX()const;
	double getY()const;
	void setX(double);
	void setY(double);
};

