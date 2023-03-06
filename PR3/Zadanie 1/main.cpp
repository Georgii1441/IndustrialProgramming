#include <iostream>
#include <cmath>
#include "eq2.h";

using namespace std;

int main() {
	setlocale(0, "");
	srand(time(0));
	int X;
	double a, b, c;
	cin >> a >> b >> c;
	Eq2 example(a, b, c);
	double *rezult_for_X = example.find_X();

	if (rezult_for_X[0] == NULL) {
		cout << "Корней нет;" << endl;
	}
	else if (rezult_for_X[0] == 1) {
		cout << "Один корень уравнения: " << rezult_for_X[1] << ";" << endl;
	}
	else {
		cout << "Два кореня уравнения, больший из них: " << rezult_for_X[1] << ";" << endl;
	}
	
	X = rand() % 20;
	cout << "Значение квадратного уравнения в точке " << X << " равно: " << example.find_Y(X) << ";";

	return 0;
}