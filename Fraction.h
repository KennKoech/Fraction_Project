#pragma once
class Fraction
{
	unsigned int numerator;
	unsigned int denominator;
public:
	Fraction();
	Fraction(unsigned int, unsigned int);

	void setDenominator(unsigned const int);
	unsigned int getDenominator() const;
	
	void setNumerator(unsigned const int);
	unsigned int getNumerator() const;

	Fraction operator+(const Fraction &);
	Fraction operator*(const Fraction &);
	friend void displayFraction(const Fraction &);
	Fraction(const Fraction&);
};

