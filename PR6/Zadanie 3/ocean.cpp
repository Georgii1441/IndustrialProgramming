#include "ocean.h"
#include <Windows.h>

void Ocean::add_sea()
{
	Sea* subarray = new Sea[seas_count + 1];
	for (int i = 0; i < seas_count; i++)
	{
		subarray[i] = seas[i];
	}
	seas_count++;
	seas = subarray;
}

void Ocean::set_name(string N)
{
	name = N;
}
void Ocean::set_deep(float D)
{
	deep = D;
}
void Ocean::set_size(float S)
{
	size = S;
}


ostream& operator<<(ostream& stream, const Ocean obj)
{
	stream << obj.name << " океан: ";
	stream << "глубина: " << obj.deep << "м; ";
	stream << "размер: " << obj.size << " тыс км2;";

	if (obj.seas_count == 0) stream << "\n  У этого океана нет морей.";

	for (int i = 0; i < obj.seas_count; i++)
	{
		stream << "\n  " << obj.seas[i];
	}

	return stream;
}
istream& operator>>(istream& stream, Ocean& obj)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	stream >> obj.name >> obj.deep >> obj.size;
	return stream;
}