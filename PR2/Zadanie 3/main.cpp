#include <iostream>
#include <cmath>
#include "figure.h";

using namespace std;

int main() {
	setlocale(0, "");
	Figure mas[3];
	double x1, x2, x3, x4, y1, y2, y3, y4;
	for (int i = 0; i < 3; i++) {
		cout << "Введите координаты сначала по x затем по y для фигуры №" << i + 1 << " через пробел: " << endl;
		cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
		mas[i].figure(x1, x2, x3, x4, y1, y2, y3, y4);
	}
	for (int i = 0; i < 3; i++) {
		mas[i].show(i + 1);

		if (mas[i].is_plug() == true)
			cout << "Данная фигура является прямоугольником" << endl;
		else
			cout << "Данная фигура не является прямоугольником" << endl;

		if (mas[i].is_square() == true)
			cout << "Данная фигура является квадратом" << endl;
		else
			cout << "Данная фигура не является квадратом" << endl;

		if (mas[i].is_romb() == true)
			cout << "Данная фигура является ромбом" << endl;
		else
			cout << "Данная фигура не является ромбом" << endl;

		if (mas[i].is_in_circle() == true)
			cout << "Данную фигуру можно вписать в окружность" << endl;
		else
			cout << "Данную фигуру нельзя вписать в окружность" << endl;

		if (mas[i].is_out_circle() == true)
			cout << "В данную фигуру можно вписать окружность" << endl;
		else
			cout << "В данную фигуру нельзя вписать окружность" << endl;
	}

	return 0;
}