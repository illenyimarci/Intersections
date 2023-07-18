#include "Parabola.h"
#include "Line.h"


Parabola::Parabola() : p(0), z(Coordinate(0.0, 0.0)) {}

Parabola::Parabola(double a, Coordinate c) : p(a) {
	z.setX(c.getX());
	z.setY(c.getY());
}

double Parabola::getP()const {
	return p;
}

Coordinate Parabola::getz()const {
	return z;
}

void Parabola::setP(double n) {
	p = n;
}

void Parabola::setZ(double x, double y) {
	z.setX(x);
	z.setY(y);
}


Coordinate* Parabola::LineIntersection(Line& L) {
	Coordinate nV = L.nVector();
	double m, be, disc, a, b, c, u, v;

	m = -(nV.getX() / nV.getY());
	be = nV.getX() / nV.getY() * L.getPoint1().getX() + L.getPoint1().getY();

	u = this->getz().getX();
	v = this->getz().getY();
	a = 0.5 * this->getP();
	b = (-1 * (this->getP() * v) - m);
	c = (0.5 * this->getP() * u * u) + v - be;

	disc = b * b - 4 * a * c;

	if (disc < 0) {
		throw std::string("Az egyenes nem metszi a parabolat");
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

Coordinate* Parabola::ParabolaIntersection(Parabola& P) {
	double disc, a, b, c, u, v, w, z;

	u = this->getz().getX();
	v = this->getz().getY();
	w = P.getz().getX();
	z = P.getz().getY();

	a = 0.5 * this->getP() - 0.5 * P.getP();
	b = w * P.getP() - u * this->getP();
	c = 0.5 * this->getP() * u * u - 0.5 * P.getP() * w * w + v - z;

	disc = b * b - 4 * a * c;
	if (disc < 0) {
		throw std::string("A ket parabola nem metszi egymast.");
		Coordinate* WPoint = new Coordinate[1];
		WPoint[0].setX(-2000);
		WPoint[0].setY(-2000);
		return WPoint;
	}
	else if (disc == 0) {
		Coordinate* PPIpoint = new Coordinate[2];
		PPIpoint[0].setX((-b) / (2 * a));
		PPIpoint[0].setY(((PPIpoint[0].getX() - u) * (PPIpoint[0].getX() - u) / 2 * this->getP()) + v);

		PPIpoint[1].setX((-b) / (2 * a));
		PPIpoint[1].setY(((PPIpoint[0].getX() - u) * (PPIpoint[0].getX() - u) / 2 * this->getP()) + v);

		return PPIpoint;
	}
	else {
		Coordinate* PPIpoints = new Coordinate[2];
		PPIpoints[0].setX(((-b) + sqrt(disc)) / (2 * a));
		PPIpoints[0].setY(((PPIpoints[0].getX() - u) * (PPIpoints[0].getX() - u) / 2 * this->getP()) + v);
		PPIpoints[1].setX(((-b) - sqrt(disc)) / (2 * a));
		PPIpoints[1].setY(((PPIpoints[1].getX() - u) * (PPIpoints[1].getX() - u) / 2 * this->getP()) + v);

		return PPIpoints;
	}
}

Coordinate* Parabola::CircleIntersection(Circle& other) {
	Coordinate* ptest= new Coordinate[1];
	ptest[0].setX(0.0);
	ptest[0].setY(0.0);
	return ptest;
}