#include <iostream>
#include <string>

using namespace std;

class Bay
{
private:
	string name;
	float deep;
	float size;

	string names_of_baies[10] = {
		"Абу-Кир",
		"Аднар-фьорд",
		"Алеутка",
		"Балос",
		"Вест-фьорд",
		"Долларт",
		"Енисейский залив",
		"Залив Гёкова",
		"Зёйдерзе",
		"Килиниос"
	};

public:
	Bay()
	{
		name = names_of_baies[rand() % 10];
		deep = rand() % 8500 + 3500;
		size = (rand() % 10000 + 2000) / 10.0;
	}
	Bay(string N, float D, float S)
	{
		name = N;
		deep = D;
		size = S;
	}

	void set_name(string N);
	void set_deep(float D);
	void set_size(float S);

	friend ostream& operator<<(ostream& stream, const Bay obj);
	friend istream& operator>>(istream& stream, Bay& obj);
};
