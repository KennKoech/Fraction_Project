#pragma once
#include "Fraction.h"
#include <ostream>
using namespace std;
class SignedFraction :
    public Fraction
{
private:
    bool isSigned;
public:
    SignedFraction();
    SignedFraction(unsigned int, unsigned int, bool);
    SignedFraction(const SignedFraction&);
    void setIsSigned(const bool);
    bool getIsSigned() const;
    SignedFraction operator +(const SignedFraction&);
    SignedFraction operator *(const SignedFraction&);
    bool operator <(const SignedFraction&);
    bool operator >(const SignedFraction&);
    bool operator ==(const SignedFraction&);
    friend ostream& operator <<(ostream&, SignedFraction&);
    // how to check for issigned before multiplication or addition
};

