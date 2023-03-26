#include "sea.h"
#include <Windows.h>

void Sea::add_bay()
{
	Bay* subarray = new Bay[baies_count + 1];
	for (int i = 0; i < baies_count; i++)
	{
		subarray[i] = baies[i];
	}
	baies_count++;
	baies = subarray;
}

void Sea::set_name(string N)
{
	name = N;
}
void Sea::set_deep(float D)
{
	deep = D;
}
void Sea::set_size(float S)
{
	size = S;
}

ostream& operator<<(ostream& stream, Sea obj)
{
	stream << obj.name << " море: ";
	stream << "глубина: " << obj.deep << "м; ";
	stream << "размер: " << obj.size << " тыс км2;";

	if (obj.baies_count == 0) stream << "\n    У этого моря нет заливов.";

	for (int i = 0; i < obj.baies_count; i++)
	{
		stream << "\n    " << obj.baies[i];
	}

	return stream;
}
istream& operator>>(istream& stream, Sea& obj)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	stream >> obj.name >> obj.deep >> obj.size;
	return stream;
}