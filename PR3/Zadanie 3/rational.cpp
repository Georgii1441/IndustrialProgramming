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

void Rational::get(int& a1, int& b1)
{
	a1 = a;
	b1 = b;
}


void Rational::show() {
	if ((a == 0) && (b == 0))
		cout << "Знаменатель не должен быть равен 0";
	else if ((a != 0) && (b == 0))
		cout << "Дробь можно представить в виде целого числа: " << a;
	else
		cout << to_string(a) + "/" + to_string(b);
}

Rational operator + (Rational fraction_1, Rational fraction_2)
{
	int a1, b1, a2, b2;

	fraction_1.get(a1, b1);
	fraction_2.get(a2, b2);

	int a, b;

	b = b1 * b2;

	a = a1 * b2 + a2 * b1;

	cout << a1 * b2 + a2 * b1 << endl;

	Rational answer(a, b);

	return answer;

}

Rational operator - (Rational fraction_1, Rational fraction_2)
{
	int a1, b1, a2, b2;

	fraction_1.get(a1, b1);
	fraction_2.get(a2, b2);

	int a, b;

	b = b1 * b2;

	a = a1 * b2 - a2 * b1;

	Rational answer(a, b);

	return answer;

}

Rational& Rational::operator ++ ()
{
	a = a + 1;
	set(a, b);

	return *this;
}

bool operator == (Rational fraction_1, Rational fraction_2)
{
	int a1, b1, a2, b2;
	fraction_1.get(a1, b1);
	fraction_2.get(a2, b2);

	return (a1 == a2 && b1 == b2);

}

bool operator > (Rational fraction_1, Rational fraction_2)
{
	int a1, b1, a2, b2;
	fraction_1.get(a1, b1);
	fraction_2.get(a2, b2);
	
	int a;

	a1 = a1 * b2;
	a2 = a2 * b1;

	return (a1 > a2);

}