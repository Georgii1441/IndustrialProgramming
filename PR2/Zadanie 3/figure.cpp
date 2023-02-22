#include <iostream>
#include <cmath>
#include "figure.h"

using namespace std;

double distance(float x1, float y1, float x2, float y2){
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));;
}

double for_square(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	return (180 / 3.14) * acos((abs((x1 - x3) * (x2 - x4) + (y1 - y3) * (y2 - y4))) / (sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2)) * sqrt(pow((x2 - x4), 2) + pow((y2 - y3), 2))));
}


void Figure::figure(float X1, float X2, float X3, float X4, float Y1, float Y2, float Y3, float Y4) {
	x1 = X1;
	x2 = X2;
	x3 = X3;
	x4 = X4;
	y1 = Y1;
	y2 = Y2;
	y3 = Y3;
	y4 = Y4;

	P = distance(x1, y1, x2, y2) + distance(x2, y2, x3, y3) + distance(x3, y3, x4, y4) + 
		distance(x4, y4, x1, y1);

	S = 0.5 * sin(for_square(x1, y1, x2, y2, x3, y3, x4, y4) / (180 / 3.14)) * 
		distance(x1, y1, x3, y3) * distance(x2, y2, x4, y4);
}

void Figure::show(int number_of_figure) {

	cout << endl << "Фигура №" << number_of_figure << " с координатами по x(" << x1 << ", " << x2 << ", " << x3 << ", " << x4 << ") " << "по y(" << y1 << ", " << y2 << ", " << y3 << ", " << y4 << ")" << endl;
	cout << "Периметр фигуры равен: " << P << endl;
	cout << "Площадь фигуры равна: " << S << endl;
}

bool Figure::is_plug() {
	return (for_square(x1, y1, x2, y2, x1, y1, x4, y4) == 90 && 
		for_square(x2, y2, x1, y1, x2, y2, x3, y3) == 90 &&
		for_square(x3, y3, x2, y2, x3, y3, x4, y4) == 90 &&
		for_square(x4, y4, x1, y1, x4, y4, x3, y3) == 90);
}

bool Figure::is_square() {
	return ((for_square(x1, y1, x2, y2, x1, y1, x4, y4) == 90 && 
		for_square(x2, y2, x1, y1, x2, y2, x3, y3) == 90 && 
		for_square(x3, y3, x2, y2, x3, y3, x4, y4) == 90 &&
		for_square(x4, y4, x1, y1, x4, y4, x3, y3) == 90) &&

		(distance(x1, y1, x2, y2) == distance(x2, y2, x3, y3) &&
			distance(x1, y1, x2, y2) == distance(x3, y3, x4, y4) &&
			distance(x1, y1, x2, y2) == distance(x4, y4, x1, y1))
		);
}

bool Figure::is_romb() {
	return ((distance(x1, y1, x2, y2) == distance(x2, y2, x3, y3) &&
		distance(x1, y1, x2, y2) == distance(x3, y3, x4, y4) &&
		distance(x1, y1, x2, y2) == distance(x4, y4, x1, y1)));
}

bool Figure::is_in_circle() {
	return (distance(x1, y1, x2, y2) + distance(x3, y3, x4, y4) == distance(x2, y2, x3, y3) + distance(x4, y4, x1, y1));
}

bool Figure::is_out_circle() {
	return ((for_square(x1, y1, x2, y2, x1, y1, x4, y4) + for_square(x3, y3, x2, y2, x3, y3, x4, y4) == 180) &&
		(for_square(x2, y2, x1, y1, x2, y2, x3, y3) + for_square(x4, y4, x1, y1, x4, y4, x3, y3) == 180));
}