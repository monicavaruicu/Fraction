#include "Fraction.h"

Fraction::Fraction(int myNumerator, int myDenominator)
{

	if (myNumerator < 0 && myDenominator < 0)
	{
		myNumerator = abs(myNumerator);
		myDenominator = abs(myDenominator);
	}

	numerator = myNumerator;
	
	if (myDenominator == 0)
	{
		std::cout << "You can't divide by 0!";
		exit(1);
	}

	denominator = myDenominator;
}


Fraction::~Fraction()
{

}

Fraction Fraction::operator+(const Fraction& fractionalNumber)
{
	Fraction sum;

	sum.numerator = numerator * fractionalNumber.denominator + denominator * fractionalNumber.numerator;
	sum.denominator = denominator * fractionalNumber.denominator;

	return sum;
}

Fraction Fraction::operator+(const int& myInteger)
{
	Fraction sum;

	sum.numerator = numerator + denominator * myInteger;
	sum.denominator = denominator;

	return sum;
}

Fraction Fraction::operator-(const Fraction& fractionalNumber)
{
	Fraction diff;

	diff.numerator = numerator * fractionalNumber.denominator - denominator * fractionalNumber.numerator;
	diff.denominator = denominator * fractionalNumber.denominator;

	return diff;
}

Fraction Fraction::operator-(const int& myInteger)
{
	Fraction diff;

	diff.numerator = numerator + denominator * myInteger;
	diff.denominator = denominator;

	return diff;
}

Fraction Fraction::operator-()
{
	numerator = -numerator;
	return *this;
}

Fraction Fraction::operator=(const Fraction& fractionalNumber)
{
	numerator = fractionalNumber.numerator;
	denominator = fractionalNumber.denominator;

	return *this;
}

Fraction Fraction::operator=(const int& myInteger)
{
	numerator = myInteger;
	denominator = 1;

	return *this;
}

Fraction Fraction::operator*(const Fraction& fractionalNumber)
{
	Fraction multi;

	multi.numerator = numerator * fractionalNumber.numerator;
	multi.denominator = denominator * fractionalNumber.denominator;

	return multi;
}

Fraction Fraction::operator*(const int& myInteger)
{
	Fraction multi;

	multi.numerator = numerator * myInteger;
	multi.denominator = denominator;

	return multi;
}

Fraction Fraction::operator/(const Fraction& fractionalNumber)
{
	Fraction div;

	div.numerator = numerator * fractionalNumber.denominator;
	div.denominator = denominator * fractionalNumber.numerator;

	return div;
}

Fraction Fraction::operator/(const int& myInteger)
{
	Fraction div;

	div.numerator = numerator;
	div.denominator = denominator * myInteger;

	return div;
}

Fraction Fraction::operator!()
{
	int factor = this->greatestCommonFactor();

	numerator = numerator / factor;
	denominator = denominator / factor;

	return *this;
}

int Fraction::greatestCommonFactor()
{
	int x = abs(numerator);
	int y = abs(denominator);

	while (y != 0)
	{
		int r = x % y;
		x = y;
		y = r;
	}

	return x;
}

bool Fraction::solveEcuation(Fraction& fr, const int& n, int* v)
{
	Fraction sum = 0;
	Fraction pow = 1;

	for (int i = 0; i <= n; i++)
	{
		sum = pow * v[i] + sum;
		pow = pow * fr;
	}

	if (sum.numerator == 0)
		return true;

	return false;
}

std::ostream& operator<<(std::ostream& os, Fraction fractionalNumber)
{
	if (fractionalNumber.denominator != 1)
		std::cout << fractionalNumber.numerator << "/" << fractionalNumber.denominator;
	else
		std::cout << fractionalNumber.numerator;

	return os;
}
