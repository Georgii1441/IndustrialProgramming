#include <iostream>
#include <cmath>
#include "rational.h";

using namespace std;

int main() {
	setlocale(0, "");
	srand(time(0));
	int size;
	cout << "Введите кол-во дробей: "; 
	cin >> size;
	cout << endl;

	Rational *mas = new Rational[size];

	int a, b;
	for (int i = 0; i < size; i++) {
		cout << "Введите попарно числитель и знаменатель для: " << i + 1 << " пары:" << endl;
		cin >> a >> b;
		mas[i].set(a, b);
	}

	for (int i = 0; i < size; i++) {
		cout << "Дробь для " << i + 1 << " пары: ";
		mas[i].show();
	}

	cout << "Замените значения числителя и знаменателя для первой дроби:" << endl;
	cin >> a >> b;
	mas[0].set(a, b);
	cout << "Дробь для 1 пары: ";
	mas[0].show();

	delete[] mas;

	return 0;
}