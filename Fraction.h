#pragma once
#include <iostream>

class Fraction
{
public:
	Fraction(int myNumerator = 0, int myDenominator = 1);
	~Fraction();
	Fraction operator+(const Fraction&);
	Fraction operator+(const int&);
	Fraction operator-(const Fraction&);
	Fraction operator-(const int&);
	Fraction operator-();
	Fraction operator=(const Fraction&);
	Fraction operator=(const int&);
	Fraction operator*(const Fraction&);
	Fraction operator*(const int&);
	Fraction operator/(const Fraction&);
	Fraction operator/(const int&);
	Fraction operator!();
	int greatestCommonFactor();
	bool solveEcuation(Fraction&, const int&, int*);
	friend std::ostream& operator<<(std::ostream& os, Fraction);


private:
	int numerator;
	int denominator;
};

