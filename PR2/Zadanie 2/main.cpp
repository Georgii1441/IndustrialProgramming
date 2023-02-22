#include <iostream>
#include <cmath>
#include "circle.h";

using namespace std;

int main() {
	setlocale(0, "");
	Circle mas[3];
	double r, x_cntr, y_cntr;
	double a, b, c;
	for (int i = 0; i < 3; i++) {
		cout << "Введите радиус окружности, координаты по x и y соответственно для окружности №" << i + 1 << " через пробел: " << endl;
		cin >> r >> x_cntr >> y_cntr;
		mas[i].set_circle(r, x_cntr, y_cntr);
	}
	for (int i = 0; i < 3; i++) {
		mas[i].circle(i + 1);
		cout << "Площадь окружности равна: " << mas[i].square() << endl;
		cout << "Введите стороны треугольника через пробел: " << endl;
		cin >> a >> b >> c;

		if (mas[i].triangle_around(a, b, c) == true)
			cout << "Вокруг данного треугольника можно описать окружность" << endl;
		else
			cout << "Вокруг данного треугольника нельзя описать окружность" << endl;

		cout << "Введите стороны треугольника через пробел: " << endl;
		cin >> a >> b >> c;

		if (mas[i].triangle_in(a, b, c) == true)
			cout << "В данный треугольник можно вписать окружность" << endl;
		else
			cout << "В данный треугольник нельзя вписать окружность" << endl;

		cout << "Введите радиус окружности, координаты по x и y через пробел соответственно: " << endl;
		cin >> r >> x_cntr >> y_cntr;

		if (mas[i].check_circle(r, x_cntr, y_cntr) == true)
			cout << "Введённая окружность пересекается с данной" << endl;
		else
			cout << "Введённая окружность не пересекается с данной" << endl;
	}

	return 0;
}