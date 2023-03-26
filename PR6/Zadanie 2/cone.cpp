#include <cmath>
#include "truncated_cone.h"

void Cone::setCoordinate(double X, double Y, double Z)
{
	x = X;
	y = Y;
	z = Z;
}

void Cone::setRadius(double r)
{
	R = r;
}

void Cone::setHeight(double h)
{
	H = h;
}

void Cone::getCoordinate(double& X, double& Y, double& Z)
{
	X = x;
	Y = y;
	Z = z;
}

double Cone::getRadius()
{
	return R;
}

double Cone::getHeight()
{
	return H;
}

double Cone::area()
{
	return PI * R * (R + sqrt(H * H + R * R));
}

double Cone::volume()
{
	return PI * R * R * H / 3;
}

ostream& operator<<(ostream& stream, Cone obj)
{
	stream << "(" << obj.x << "; ";
	stream << obj.y << "; ";
	stream << obj.z << ") ";
	stream << "r = " << obj.R << " ";
	stream << "h = " << obj.H << "";
	return stream;
}