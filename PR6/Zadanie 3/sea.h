#include <iostream>
#include <string>
#include "bay.h"

using namespace std;

class Sea : 
	private Bay
{
private:
	string name;
	float deep;
	float size;

	int baies_count = 0;

	string names_of_seas[10] = {
		"Андаманское",
		"Аравийское",
		"Саргассово",
		"Гренландское",
		"Белое",
		"Жёлтое",
		"Карибское",
		"Красное",
		"Балтийское",
		"Коралловаое"
	};

public:
	Bay* baies = new Bay[baies_count];

	Sea()
	{
		name = names_of_seas[rand() % 10];
		deep = rand() % 8500 + 3500;
		size = (rand() % 100000 + 20000) / 10.0;
	}
	Sea(string N, float D, float S)
	{
		name = N;
		deep = D;
		size = S;
	}

	void add_bay();

	void set_name(string N);
	void set_deep(float D);
	void set_size(float S);

	friend ostream& operator<<(ostream& stream, const Sea obj);
	friend istream& operator>>(istream& stream, Sea& obj);
};