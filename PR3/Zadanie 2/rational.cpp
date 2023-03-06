#include <iostream>
#include <cmath>
#include <string>
#include "rational.h"

using namespace std;


Rational::Rational() {
	a = 0; b = 0;
}

Rational::Rational(int a1, int b1) {
	if ((a1 == 0) && (b1 != 0)) {
		a = a1; b = b1;
	}

	else if (b1 != 0) {
		a = a1; b = b1;
		if (a >= b) {
			if (a % b == 0) {
				a = a / b;
				b = 0;
			}
			else {
				a = a - int((a / b)) * b;
			}
		}

		else if ((b % a == 0) && (a != 1)) {
			b /= a;
			a = 1;
		}
	}

	else {
		a = 0; 
		b = 0;
	}
}

void Rational::set(int a1, int b1) {
	if ((a1 == 0) && (b1 != 0)) {
		a = a1; b = b1;
	}

	else if (b1 != 0) {
		a = a1; b = b1;
		if (a >= b) {
			if (a % b == 0) {
				a = a / b;
				b = 0;
			}
			else {
				a = a - int((a / b)) * b;
			}
		}

		else if ((b % a == 0) && (a != 1)) {
			b /= a;
			a = 1;
		}
	}

	else {
		a = 0;
		b = 0;
	}
}

void Rational::show() {
	if ((a == 0) && (b == 0))
		cout << "Знаменатель не должен быть равен 0" << endl;
	else if ((a != 0) && (b == 0))
		cout << "Дробь можно представить в виде целого числа: " << a << endl;
	else
		cout << to_string(a) + "/" + to_string(b) << endl;
}