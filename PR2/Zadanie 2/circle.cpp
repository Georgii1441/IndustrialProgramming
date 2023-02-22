#include <iostream>
#include <cmath>
#include "circle.h"

using namespace std;

void Circle::circle(int number_of_circle) {
	cout << "Окружность №" << number_of_circle << " с радиусом : " << radius << ", " << "координатами : " << x_center << ", " << y_center << endl;
}

void Circle::set_circle(float r, float x_cntr, float y_cntr) {
	radius = r;
	x_center = x_cntr;
	y_center = y_cntr;
}

float Circle::square() {
	return 3.14 * pow(radius, 2);
}

bool Circle::triangle_around(float a, float b, float c) {
	if (((a + b > c) && (b + c > a) && (a + c > b)) == true)
		return true;
	else 
		return false;
}

bool Circle::triangle_in(float a, float b, float c) {
	if (((a + b > c) && (b + c > a) && (a + c > b)) == true)
		return true;
	else
		return false;
}

bool Circle::check_circle(float r, float x_cntr, float y_cntr) {
	if (pow(pow(abs(x_center - x_cntr), 2) + pow(abs(y_center - y_cntr), 2), 0.5) <= radius + r)
		return true;
	else
		return false;
}