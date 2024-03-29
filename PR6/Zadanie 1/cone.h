class Cone
{
private:
	const double PI = 3.141592;
	double x, y, z;
	double R;
	double H;

public:
	Cone()
	{
		x = 0;
		y = 0;
		z = 0;
		R = 0;
		H = 0;
	}

	Cone(double X, double Y, double Z, double r, double h)
	{
		x = X;
		y = Y;
		z = Z;
		R = r;
		H = h;
	}

	void setCoordinate(double X, double Y, double Z);
	void setRadius(double r);
	void setHeight(double h);
	void getCoordinate(double& X, double& Y, double& Z);
	double getRadius();
	double getHeight();
	double area();
	double volume();
};