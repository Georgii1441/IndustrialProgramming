#include <iostream>
#include "Ocean.h"

using namespace std;

int main()
{
	setlocale(0, "");
	srand(time(0));

	Ocean item_1, item_2, item_3, item_4;
	item_1.add_sea();
	item_1.add_sea();
	item_1.seas[0].add_bay();
	item_1.seas[0].add_bay();
	item_1.seas[1].add_bay();
	item_1.seas[1].add_bay();
	item_1.seas[1].add_bay();
	item_3.add_sea();

	cout << item_1 << "\n";
	cout << item_2 << "\n";
	cout << item_3 << "\n";

	item_4.add_sea();
	item_4.seas[0].add_bay();

	cout << "\nВведите данные океана (Название, глубина, размер):";
	cin >> item_4;
	cout << "Введите данные моря (Название, глубина, размер):";
	cin >> item_4.seas[0];
	cout << "Введите данные залива (Название, глубина, размер):";
	cin >> item_4.seas[0].baies[0];

	cout << "\n";

	cout << item_4;

	cout << "\n";

	return 0;
}