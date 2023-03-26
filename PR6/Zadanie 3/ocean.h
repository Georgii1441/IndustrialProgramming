#include <iostream>
#include <string>
#include "sea.h"

using namespace std;

class Ocean : 
	private Sea
{
private:
	string name;
	float deep;
	float size;

	string names_of_ocean[5] = {
		"Тихий",
		"Атлантический",
		"Индийский",
		"Северный Ледовитый",
		"Южный"
	};

public:
	int seas_count = 0;
	Sea* seas = new Sea[seas_count];

	void add_sea();

	Ocean()
	{
		name = names_of_ocean[rand() % 5];
		deep = rand() % 8500 + 3500;
		size = (rand() % 1000000 + 200000) / 10.0;
	}
	Ocean(string N, float D, float S)
	{
		name = N;
		deep = D;
		size = S;
	}

	void set_name(string N);
	void set_deep(float D);
	void set_size(float S);

	friend ostream& operator<<(ostream& stream, const Ocean obj);
	friend istream& operator>>(istream& stream, Ocean& obj);
};