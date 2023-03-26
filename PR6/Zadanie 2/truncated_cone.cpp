#include <iostream>
#include "truncated_cone.h"

using namespace std;

void Truncated_cone::setCoordinate(double X, double Y, double Z)
{
	x = X;
	y = Y;
	z = Z;
}

void Truncated_cone::setRadius(double r)
{
	R = r;
}

void Truncated_cone::setHeight(double h, double trunc_h)
{
	H = h;
	trunc_H = trunc_h;
}

void Truncated_cone::getCoordinate(double& X, double& Y, double& Z)
{
	X = x;
	Y = y;
	Z = z;
}

double Truncated_cone::getRadius()
{
	return R;
}

double Truncated_cone::getHeight(double& h, double& trunc_h)
{
	h = H;
	trunc_h = trunc_H;
	return 0;
}

double Truncated_cone::area()
{
	return (PI * R * (R + sqrt(H * H + R * R)) - PI * R * (R + sqrt((H - trunc_H) * (H - trunc_H) + R * R)));
}

double Truncated_cone::volume()
{
	return (PI * R * R * H / 3) - (PI * R * R * (H - trunc_H) / 3);
}

ostream& operator<< (ostream& stream, const Truncated_cone& obj)
{
	stream << "(" << obj.x << "; ";
	stream << obj.y << "; ";
	stream << obj.z << ") ";
	stream << "r = " << obj.R << " ";
	stream << "H = " << obj.H << " ";
	stream << "h = " << obj.trunc_H << " ";
	return stream;
}

istream& operator>> (istream& stream, Truncated_cone& obj)
{
	stream >> obj.x;
	stream >> obj.y;
	stream >> obj.z;
	stream >> obj.R;
	stream >> obj.H;
	stream >> obj.trunc_H;
	return stream;
}