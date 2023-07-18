#include "Coordinate.h"
#include "Line.h"
#include "Circle.h"
#include "Parabola.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Intersections.h"
#include <vector>

using namespace std;

int main() {
	Line line1, line2;
	Circle circle1, circle2;
	Parabola parabola;
	string fname;

	//Fájlnév bekérése
	cout << "Adjon meg egy fajlnevet: ";
	cin >> fname;
	//Fájl megnyitása
	ifstream inputfile(fname, ios::in);

	//Ellenõrzés, hogy nyitvan van
	while (!inputfile.is_open()) {
		cout << "Nem sikerult megnyitni a fajlt, adjon meg egy uj fajlnevet: ";
		string s;
		cin >> s;
		inputfile.open(s, ios::in);
	}

	//Beolvasó függvény
	string input;
	while (getline(inputfile, input)) {
		Coordinate l1, c1, p1;
		stringstream in(input), num1, num2, num3, num4, num5, num6, num7, num8;
		stringstream cnum1, cnum2, cnum3, cnum4, cnum5, cnum6;
		stringstream pnum1, pnum2, pnum3;
		string numstr;
		double inpnum;

		getline(in, numstr, '(');
		getline(in, numstr, ';');
		num1 << numstr; num1 >> inpnum;
		l1.setX(inpnum);
		getline(in, numstr, '(');
		num2 << numstr; num2 >> inpnum;
		l1.setY(inpnum);
		line1.setPoint1(l1.getX(), l1.getY());

		getline(in, numstr, ';');
		num3 << numstr; num3 >> inpnum;
		l1.setX(inpnum);
		getline(in, numstr, '(');
		num4 << numstr; num4 >> inpnum;
		l1.setY(inpnum);
		line1.setPoint2(l1.getX(), l1.getY());

		getline(in, numstr, ';');
		num5 << numstr; num5 >> inpnum;
		l1.setX(inpnum);
		getline(in, numstr, '(');
		num6 << numstr; num6 >> inpnum;
		l1.setY(inpnum);
		line2.setPoint1(l1.getX(), l1.getY());

		getline(in, numstr, ';');
		num7 << numstr; num7 >> inpnum;
		l1.setX(inpnum);
		getline(in, numstr, '(');
		num8 << numstr; num8 >> inpnum;
		l1.setY(inpnum);
		line2.setPoint2(l1.getX(), l1.getY());

		getline(in, numstr, ';');
		cnum1 << numstr; cnum1 >> inpnum;
		c1.setX(inpnum);
		getline(in, numstr, ' ');
		cnum2 << numstr; cnum2 >> inpnum;
		c1.setY(inpnum);
		getline(in, numstr, '(');
		cnum3 << numstr; cnum3 >> inpnum;
		circle1.setCenterpoint(c1.getX(), c1.getY());
		try {
				circle1.setRange(inpnum);
		}
		catch (string a) {
			cout << a << endl;
			cout << "Adjon meg egy uj sugarerteket az elso korhoz: ";
			double r1;
			cin >> r1;
			while (r1 <= 0) {
				cout << "A megadott ertek nem lehet negativ szam! Adja meg ujra: ";
				cin >> r1;
			}
			circle1.setRange(r1);
		}

		getline(in, numstr, ';');
		cnum4 << numstr; cnum4 >> inpnum;
		c1.setX(inpnum);
		getline(in, numstr, ' ');
		cnum5 << numstr; cnum5 >> inpnum;
		c1.setY(inpnum);
		getline(in, numstr, '=');
		cnum6 << numstr; cnum6 >> inpnum;
		circle2.setCenterpoint(c1.getX(), c1.getY());
		try {
			circle2.setRange(inpnum);
		}
		catch(string b) {
			cout << b << endl;
			cout << "Adjon meg egy uj sugarerteket a masodik korhoz: ";
			double r2;
			cin >> r2;
			while (r2 <= 0) {
				cout << "A megadott ertek nem lehet negativ szam!";
				cin >> r2;
			}
			circle2.setRange(r2);
		}

		getline(in, numstr, '*');
		getline(in, numstr, '(');
		pnum1 << numstr; pnum1 >> inpnum;
		parabola.setP(inpnum);
		getline(in, numstr, 'x');
		getline(in, numstr, ')');
		pnum2 << numstr; pnum2 >> inpnum;
		p1.setX(-1 * inpnum);
		getline(in, numstr, '+');
		getline(in, numstr, ' ');
		pnum3 << numstr; pnum3 >> inpnum;
		p1.setY(inpnum);
		parabola.setZ(p1.getX(), p1.getY());
		int y = 0;
	}
	inputfile.close();

	Coordinate* Cinterpoint;
	Coordinate* CCinterpoint;
	Coordinate* Pinterpoint;
	Coordinate* Linterpoint;

	//Metsszõfüggvények tesztelése
	try {
		Linterpoint = line1.LineIntersection(line2);
	}
	catch (string err0) {
		cout << err0 << endl;
		return -1;
	}

	try {
		Cinterpoint = line1.CircleIntersection(circle1);
	}
	catch (string err1) {
		cout << err1 << endl;
		return -1;
	}

	try {
		Pinterpoint = line1.ParabolaIntersection(parabola);
	}
	catch (string err2) {
		cout << err2 << endl;
		return -1;
	}

	try {
		CCinterpoint = circle1.CircleIntersection(circle2);
	}
	catch (string err3) {
		cout << err3 << endl;
		return -1;
	}

	//Tömbök méretének vizsgálása
	int num1;
	if (Cinterpoint[0].getX() == Cinterpoint[1].getX() && Cinterpoint[0].getY() == Cinterpoint[1].getY()) {
		num1 = 1;
	}
	else{ num1 = 2; }
	int num2;
	if (CCinterpoint[0].getX() == CCinterpoint[1].getX() && CCinterpoint[0].getY() == CCinterpoint[1].getY()) {
		num2 = 1;
	}
	else { num2 = 2; }
	int num3;
	if (Pinterpoint[0].getX() == Pinterpoint[1].getX() && Pinterpoint[0].getY() == Pinterpoint[1].getY()) {
		num3 = 1;
	}
	else { num3 = 2; }

	//kiiratás
	cout << "Metszespontok: " << endl << "Kor es egyenes: ";
	for (int j = 0; j < num1; j++) {
		cout << Cinterpoint[j];
	}
	cout << endl << "Egyenes es parabola: ";
	for (int j = 0; j < num3; j++) {
		cout << Pinterpoint[j];
	}
	cout << endl << "Egyenes es masik egyenes: ";
	for (int j = 0; j < 1; j++) {
		cout << Linterpoint[j];
	}
	cout << endl << "Kor es masik kor: ";
	for (int j = 0; j < num2; j++) {
		cout << CCinterpoint[j];
	}

	//foglalt memória felszabadítása
	delete[] Linterpoint;
	delete[] Cinterpoint;
	delete[] CCinterpoint;
	delete[] Pinterpoint;

	return 0;
}