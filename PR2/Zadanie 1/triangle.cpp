#include <iostream>
#include <cmath>
#include "triangle.h"

using namespace std;


bool Triangle::exst_tr() {
	return ((a + b > c) && (b + c > a) && (a + c > b));
}

void Triangle::set(double a1, double b1, double c1) {
	a = a1;
	b = b1;
	c = c1;
}

void Triangle::show() {
	cout << endl << "1-я сторона: " << a << endl;
	cout << "2-я сторона: " << b << endl;
	cout << "3-я сторона: " << c << endl;
}

double Triangle::perimetr() {
	return a + b + c;
}

double Triangle::square() {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}