#include <iostream>
#include "cone.h"

using namespace std;

int main()
{
	setlocale(0, "");

	Cone c1(0, 0, 0, 3, 7);
	Cone c2(2, 4, 7, 12, 10);

	cout << "Площадь 1-ого конуса: " << c1.area() << endl;
	cout << "Объём 1-ого конуса: " << c1.volume() << endl;
	cout << "Площадь 2-ого конуса: " << c2.area() << endl;
	cout << "Объём 2-ого конуса: " << c2.volume() << endl;
	cout << endl;

	int size;
	double x, y, z, r, h;
	cout << "Введите кол-во конусов: ";
	cin >> size;
	Cone* cones = new Cone[size];

	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "Введите данные (координаты, радиус, высоту) конуса №" << i + 1 << ": ";
		cin >> x >> y >> z >> r >> h;
		cones[i].setCoordinate(x, y, z);
		cones[i].setRadius(r);
		cones[i].setHeight(h);
	}

	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Данные конуса №" << i + 1 << ": \n";
		cones[i].getCoordinate(x, y, z);
		cout << "x = " << x << " y = " << y << " z = " << z << endl;
		cout << "S = " << cones[i].area() << endl;
		cout << "V = " << cones[i].volume() << endl << endl;
	}

	Cone arbitrary_cones[3];
	arbitrary_cones[0].setCoordinate(2, 4, 9); arbitrary_cones[0].setRadius(21); arbitrary_cones[0].setHeight(24);
	arbitrary_cones[1].setCoordinate(3, 7, 12); arbitrary_cones[1].setRadius(6); arbitrary_cones[1].setHeight(8);
	arbitrary_cones[2].setCoordinate(2, 1, 6); arbitrary_cones[2].setRadius(0.081); arbitrary_cones[2].setHeight(0.16);

	cout << "Массив с произвольными конусами: " << endl << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Данные конуса №" << i + 1 << ": \n";
		arbitrary_cones[i].getCoordinate(x, y, z);
		cout << "x = " << x << " y = " << y << " z = " << z << endl;
		cout << "S = " << arbitrary_cones[i].area() << endl;
		cout << "V = " << arbitrary_cones[i].volume() << endl << endl;
	}

	return 0;
}