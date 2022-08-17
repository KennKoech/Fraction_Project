#include "SignedFraction.h"

SignedFraction::SignedFraction(): SignedFraction(0,1, false)
{
}

SignedFraction::SignedFraction(unsigned int num, unsigned int denom, bool sign)
{
	setNumerator(num);
	setDenominator(denom);
	isSigned = sign;
}

SignedFraction::SignedFraction(const SignedFraction& signedFraction)
{
	setNumerator(signedFraction.getNumerator());
	setDenominator(signedFraction.getDenominator());
}

void SignedFraction::setIsSigned(const bool sign)
{
	isSigned = sign;
}

bool SignedFraction::getIsSigned() const
{
	return isSigned;
}

SignedFraction SignedFraction::operator+(const SignedFraction& signedFraction)
{
	int commonDenom = getDenominator() * signedFraction.getDenominator();

	SignedFraction result((commonDenom / getDenominator() * getNumerator()) + (commonDenom / signedFraction.getDenominator() * signedFraction.getNumerator()), commonDenom, signedFraction.isSigned);
	return result;
}

SignedFraction SignedFraction::operator*(const SignedFraction& signedFraction)
{
	SignedFraction result(getNumerator() * signedFraction.getNumerator(), getDenominator() *  signedFraction.getDenominator(), signedFraction.isSigned);
	return result;
}

bool SignedFraction::operator <(const SignedFraction& signedFraction) {
	if (getNumerator()/getDenominator() < signedFraction.getNumerator()/signedFraction.getDenominator()) {
		return true;
	}
	else 
		return false;
}

// I overloaded the greater than and the equal to operators because I need them for the binary search.
bool SignedFraction::operator>(const SignedFraction& signedFraction)
{
	if (getNumerator() / getDenominator() < signedFraction.getNumerator() / signedFraction.getDenominator()) {
		return false;
	}
	else
		return true;
}

bool SignedFraction::operator==(const SignedFraction& signedFraction)
{
	if (getDenominator() == signedFraction.getDenominator() && getNumerator() == signedFraction.getNumerator())
		return true;
	else
		return false;
}

ostream& operator<<(ostream& str, SignedFraction& signedFraction)
{
	str << signedFraction.getNumerator() << "/" << signedFraction.getDenominator();
	return str;
}
