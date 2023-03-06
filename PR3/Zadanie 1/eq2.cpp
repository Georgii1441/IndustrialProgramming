#include <iostream>
#include <cmath>
#include "eq2.h"

using namespace std;


Eq2::Eq2(double a1, double b1, double c1) {
	a = a1; b = b1; c = c1;
	D = pow(b, 2) - 4 * a * c;
}

void Eq2::set(double a1, double b1, double c1) {
	a = a1; b = b1; c = c1;
	D = pow(b, 2) - 4 * a * c;
}

double *Eq2::find_X() {
	static double array[2];

	if (D < 0) {
		array[0] = NULL;
	}
	else if (D == 0) {
		array[0] = 1;
		array[1] = (-b - sqrt(D)) / (2 * a);
	}
	else {
		double x1 = (-b - sqrt(D)) / (2 * a);
		double x2 = (-b + sqrt(D)) / (2 * a);
		array[0] = 2;
		if (x1 > x2) {
			array[1] = x1;
		}
		else {
			array[1] = x2;
		}
	}

	return array;
}

double Eq2::find_Y(double x1) {
	return a * pow(x1, 2) + b * x1 + c;
}