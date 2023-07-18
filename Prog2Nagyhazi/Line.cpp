#include "Line.h"

Line::Line() {
	point1 = Coordinate(0.0, 0.0);
	point2 = Coordinate(0.0, 0.0);
}

Line::Line(Coordinate a, Coordinate b) {
	point1.setX(a.getX());
	point1.setY(a.getY());

	point2.setX(b.getX());
	point2.setY(b.getY());
}

Coordinate Line::nVector() {
	Coordinate nV;
	nV.setX(point1.getX() - point2.getX());
	nV.setY(point1.getY() - point2.getY());

	double temp;
	temp = nV.getX();
	nV.setX(nV.getY());
	nV.setY(-temp);

	return nV;
}

Coordinate Line::getPoint1()const {
	return point1;
}

Coordinate Line::getPoint2()const {
	return point2;
}

void Line::setPoint1(double x, double y) {
	point1.setX(x);
	point1.setY(y);
}

void Line::setPoint2(double x, double y) {
	point2.setX(x);
	point2.setY(y);
}

Coordinate* Line::LineIntersection(Line& other){
	Coordinate* Ipoint = new Coordinate[1];

	Coordinate e1 = this->nVector();
	Coordinate e2 = other.nVector();

	double m1 = -(e1.getX() / e1.getY());
	double m2 = -(e2.getX() / e2.getY());

	if (m1 == m2) {
		throw std::string("A ket egyenes parhuzamos egymassal");
		Ipoint[0].setX(-100);
		Ipoint[0].setY(-100);
		return Ipoint;
	}
	else {
		double c1 = (e1.getX() / e1.getY()) * point1.getX() + point1.getY();
		double c2 = (e2.getX() / e2.getY()) * other.getPoint1().getX() + other.getPoint1().getY();

		Ipoint[0].setX((c2 - c1) / (m1 - m2));
		Ipoint[0].setY(m1 * Ipoint[0].getX() + c1);

		return Ipoint;
	}
}


Coordinate* Line::CircleIntersection(Circle& other) {
	double disc, m, be, a, b, c, u, v;
	Coordinate nV = this->nVector();
	u = other.getCenterpoint().getX();
	v = other.getCenterpoint().getY();

	m = -(nV.getX() / nV.getY());
	be = (nV.getX() / nV.getY() * point1.getX()) + point1.getY();

	a = m * m + 1;
	b = 2 * m * be - 2 * u - 2 * m * v;
	c = be * be - (2 * be * v) + v * v - other.getRange() * other.getRange() + (u * u);

	disc = b * b - (4 * a * c);

	if (disc < 0) {
		throw std::string("Az egyenes nem metszi a kort.");
		Coordinate* WPoint = new Coordinate[1];
		WPoint[0].setX(-1000);
		WPoint[0].setY(-1000);
		return WPoint;
	}

	else if (disc == 0) {
		Coordinate* LCIpoint = new Coordinate[2];
		LCIpoint[0].setX(-1 * b / 2 * a);
		LCIpoint[0].setY(m * LCIpoint[0].getX() + be);

		LCIpoint[1].setX(-1 * b / 2 * a);
		LCIpoint[1].setY(m * LCIpoint[0].getX() + be);

		return LCIpoint;
	}

	else {
		Coordinate* LCIpoints = new Coordinate[2];
		LCIpoints[0].setX(((-1 * b) + sqrt(disc)) / (2 * a));
		LCIpoints[0].setY(m * LCIpoints[0].getX() + be);

		LCIpoints[1].setX(((-1 * b) - sqrt(disc)) / (2 * a));
		LCIpoints[1].setY(m * LCIpoints[1].getX() + be);

		return LCIpoints;
	}
}

Coordinate* Line::ParabolaIntersection(Parabola& other) {
	Coordinate nV = this->nVector();
	double m, be, disc, a, b, c, u, v;

	m = -(nV.getX() / nV.getY());
	be = nV.getX() / nV.getY() * point1.getX() + point1.getY();

	u = other.getz().getX();
	v = other.getz().getY();
	a = 0.5 * other.getP();
	b = (-1 * (other.getP() * v) - m);
	c = (0.5 * other.getP() * u * u) + v - be;

	disc = b * b - 4 * a * c;

	if (disc < 0) {
		throw std::string("Az egyenes nem metszi a parabolat.");
		Coordinate* WPoint = new Coordinate[1];
		WPoint[0].setX(-1000);
		WPoint[0].setY(-1000);
		return WPoint;
	}
	else if (disc == 0) {
		Coordinate* LPIpoint = new Coordinate[2];
		LPIpoint[0].setX((-b) / (2 * a));
		LPIpoint[0].setY(m * LPIpoint[0].getX() + be);

		LPIpoint[1].setX((-b) / (2 * a));
		LPIpoint[1].setY(m * LPIpoint[0].getX() + be);

		return LPIpoint;
	}
	else {
		Coordinate* LPIpoints = new Coordinate[2];
		LPIpoints[0].setX(((-b) + sqrt(disc)) / (2 * a));
		LPIpoints[0].setY(m * LPIpoints[0].getX() + be);

		LPIpoints[1].setX(((-b) - sqrt(disc)) / (2 * a));
		LPIpoints[1].setY(m * LPIpoints[1].getX() + be);

		return LPIpoints;
	}
}
