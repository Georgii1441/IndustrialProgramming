#pragma once
#include "cone.h"

using namespace std;

class Truncated_cone:
	public Cone
{
private:
	const double PI = 3.141592;
	double x, y, z;
	double R;
	double H;
	double trunc_H;

public:
	Truncated_cone()
	{
		x = 0;
		y = 0;
		z = 0;
		R = 0;
		H = 0;
		trunc_H = 0;
	}

	Truncated_cone(double X, double Y, double Z, double r, double h, double trunc_h)
	{
		x = X;
		y = Y;
		z = Z;
		R = r;
		H = h;
		trunc_H = trunc_h;
	}

	void setCoordinate(double X, double Y, double Z);
	void setRadius(double r);
	void setHeight(double h, double trunc_h);
	void getCoordinate(double& X, double& Y, double& Z);

	double getRadius();
	double getHeight(double& H, double& trunc_H);

	double area();
	double volume();

	friend ostream& operator << (ostream& stream, const Truncated_cone& obj);
	friend istream& operator >> (istream& stream, Truncated_cone& obj);
};