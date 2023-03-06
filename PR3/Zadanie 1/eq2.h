class Eq2 {
private:
	double a, b, c;
	double D;

public:
	Eq2(double a1, double b1, double c1);
	void set(double a1, double b1, double c1);
	double *find_X();
	double find_Y(double x1);
};
