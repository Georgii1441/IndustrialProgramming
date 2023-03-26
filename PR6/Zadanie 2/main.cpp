#include <iostream>
#include "truncated_cone.h"

using namespace std;

int main()
{
	setlocale(0, "");

	int size;
	cout << "Введите количествово усечённых конусов: ";
	cin >> size;

	Truncated_cone* Cones = new Truncated_cone[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Введите данные усчённого конуса №" << i + 1 << ": ";
		cin >> Cones[i];
	}

	for (int i = 0; i < size; i++)
	{
		cout << endl;
		cout << "Данные конуса №" << i + 1 << ": ";
		cout << Cones[i] << endl;
		cout << "S = " << Cones[i].area() << endl;
		cout << "V = " << Cones[i].volume() << endl;
	}

	return 0;
}