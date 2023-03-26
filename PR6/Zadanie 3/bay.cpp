#include "bay.h"
#include <Windows.h>

void Bay::set_name(string N)
{
	name = N;
}
void Bay::set_deep(float D)
{
	deep = D;
}
void Bay::set_size(float S)
{
	size = S;
}

ostream& operator<<(ostream& out, Bay obj)
{
	out << obj.name << " залив: ";
	out << "глубина: " << obj.deep << "м; ";
	out << "размер: " << obj.size << " тыс км2;";

	return out;
}
istream& operator>>(istream& stream, Bay& obj)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	stream >> obj.name >> obj.deep >> obj.size;
	return stream;
}