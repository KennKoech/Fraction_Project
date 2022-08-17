#include "Fraction.h"
#include <iostream>
Fraction::Fraction(): Fraction(0,1)
{
}

Fraction::Fraction(unsigned int num, unsigned int denom)
{
	numerator = num;
	denominator = denom;
}

Fraction::Fraction(const Fraction& f)
{
	numerator = f.numerator;
	denominator = f.denominator;
}

void Fraction::setDenominator(unsigned const int denom)
{
	denominator = denom;
}

unsigned int Fraction::getDenominator() const
{
	return denominator;
}

void Fraction::setNumerator(unsigned const int num)
{
	numerator = num;
}

Fraction Fraction::operator*(const Fraction &f)
{

	Fraction result((numerator * f.numerator), (denominator * f.denominator));
	return result;
}

Fraction Fraction::operator+(const Fraction &f)
{
	int commonDenom = denominator * f.denominator;
	//if (denominator < f.denominator && commonDenom % denominator == 0) {
	//	commonDenom = commonDenom / denominator;
	//}
	//if (f.denominator < denominator && commonDenom % f.denominator == 0) {
	//	commonDenom = commonDenom / f.denominator;
	//}
	Fraction result ((commonDenom/denominator * numerator + commonDenom/f.denominator * f.numerator), (commonDenom));
	return result;
}

unsigned int Fraction::getNumerator() const
{
	return numerator;
}

// This is a friend function. So instead of using getters and setters, we are able to access the private data members directly
void displayFraction(const Fraction& fr) {
	std::cout << fr.numerator << "/" << fr.denominator << std::endl;
}
