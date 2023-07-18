#include "Circle.h"

Circle::Circle() : centerpoint(Coordinate(0.0, 0.0)), range(0) {}

Circle::Circle(Coordinate a, double c) {
	setRange(c);
	centerpoint.setX(a.getX());
	centerpoint.setY(a.getY());
}

Coordinate Circle::getCenterpoint()const {
	return centerpoint;
}

double Circle::getRange()const {
	return range;
}

void Circle::setCenterpoint(double a, double b) {
	centerpoint.setX(a);
	centerpoint.setY(b);
}

void Circle::setRange(double r) {
	if (r <= 0) {
		throw std::string("Nem lehet negativ a kor sugara!");
	}
	range = r;
}

Coordinate* Circle::LineIntersection(Line& L) {
	double disc, m, be, a, b, c, u, v;
	Coordinate nV = L.nVector();
	u = this->getCenterpoint().getX();
	v = this->getCenterpoint().getY();

	m = -(nV.getX() / nV.getY());
	be = (nV.getX() / nV.getY() * L.getPoint1().getX()) + L.getPoint1().getY();

	a = m * m + 1;
	b = 2 * m * be - 2 * u - 2 * m * v;
	c = be * be - (2 * be * v) + v * v - this->getRange() * this->getRange() + (u * u);

	disc = b * b - (4 * a * c);

	if (disc < 0) {
		throw std::string("Az egyenes nem metszi a kort.");
		Coordinate* WPoint = new Coordinate[1];
		WPoint[0].setX(-1000);
		WPoint[0].setY(-1000);
		return WPoint;
	}

	else if (disc == 0) {
		Coordinate* CLIpoint = new Coordinate[2];
		CLIpoint[0].setX(-1 * b / 2 * a);
		CLIpoint[0].setY(m * CLIpoint[0].getX() + be);

		CLIpoint[1].setX(-1 * b / 2 * a);
		CLIpoint[1].setY(m * CLIpoint[0].getX() + be);

		return CLIpoint;
	}

	else {
		Coordinate* CLIpoints = new Coordinate[2];
		CLIpoints[0].setX(((-1 * b) + sqrt(disc)) / (2 * a));
		CLIpoints[0].setY(m * CLIpoints[0].getX() + be);

		CLIpoints[1].setX(((-1 * b) - sqrt(disc)) / (2 * a));
		CLIpoints[1].setY(m * CLIpoints[1].getX() + be);

		return CLIpoints;
	}
}

Coordinate* Circle::CircleIntersection(Circle& C) {
	double disc, m, bc, a, b, c, u, v, d, e;

	u = this->getCenterpoint().getX();
	v = this->getCenterpoint().getY();
	d = C.getCenterpoint().getX();
	e = C.getCenterpoint().getY();

	m = (-1 * (-2 * u + 2 * d) / (-2 * v + 2 * e));
	bc = (((-1 * (u * u)) + d * d - v * v + e * e - C.getRange() * C.getRange() + this->getRange() * this->getRange())/4.0);

	a = m * m + 1;
	b = 2 * m * bc - 2 * u - 2 * m * v;
	c = bc * bc + (-2 * bc * v) + (-1*(this->getRange() * this->getRange())) + u*u + v*v;
	disc = b * b - 4 * a * c;

	if (disc < 0) {
		throw std::string("A ket kornek nincs metszespontja.");
		Coordinate* WPoint = new Coordinate[1];
		WPoint[0].setX(-2000);
		WPoint[0].setY(-2000);
		return WPoint;
	}
	else if (disc == 0) {
		Coordinate* CCIpoint = new Coordinate[2];
		CCIpoint[0].setX((-b) / (2 * a));
		CCIpoint[0].setY(m * CCIpoint[0].getX() + bc);

		CCIpoint[1].setX((-b) / (2 * a));
		CCIpoint[1].setY(m * CCIpoint[0].getX() + bc);

		return CCIpoint;
	}
	else {
		Coordinate* CCIpoints = new Coordinate[2];
		CCIpoints[0].setX(((-b) + sqrt(disc)) / (2 * a));
		CCIpoints[0].setY(m * CCIpoints[0].getX() + bc);

		CCIpoints[1].setX(((-b) - sqrt(disc)) / (2 * a));
		CCIpoints[1].setY(m * CCIpoints[1].getX() + bc);

		return CCIpoints;
	}
}

Coordinate* Circle::ParabolaIntersection(Parabola& P) {
	Coordinate* test = new Coordinate[1];
	test[0].setX(0);
	test[0].setY(0);
	return test;
}


