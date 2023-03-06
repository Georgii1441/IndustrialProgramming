class Rational {
private:
	int a, b;

public:
	Rational();
	Rational(int a1, int b1);
	void set(int a1, int b1);
	void get(int& a1, int& b1);
	void show();

	friend Rational operator - (Rational fraction_1, Rational fraction_2);

	Rational& operator ++();
};

Rational operator + (Rational fraction_1, Rational fraction_2);

bool operator == (Rational fraction_1, Rational fraction_2);
bool operator > (Rational fraction_1, Rational fraction_2);