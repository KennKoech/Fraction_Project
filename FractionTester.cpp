#include "Fraction.h"
#include <iostream>
using namespace std;

//void displayFraction(const Fraction& fr) {
//
//	cout << fr.getNumerator() << "/" << fr.getDenominator() << endl;
//}

int main() {
	system("cls");
	Fraction testDefault;
	displayFraction(testDefault);
	//#######example 1##############
	Fraction myFraction(1, 2);
	cout << "Displaying my fraction: ";
	displayFraction(myFraction);

	//###########example 2############
	Fraction yourFraction;
	unsigned int x, y;
	cout << "\nPlease enter two positive numbers: " << endl;
	cin >> x >> y;
	yourFraction.setNumerator(x);
	yourFraction.setDenominator(y);
	cout << "\nDisplaying your fraction: ";
	displayFraction(yourFraction);

	// ##################### Testing addition and multiplication operators ######################
	cout << "Enter two other positive numbers and I will display the sum and product of your two fractions: " << endl;
	unsigned int a, b;
	cin >> a >> b;
	Fraction yourSecondFraction;
	yourSecondFraction.setNumerator(a);
	yourSecondFraction.setDenominator(b);
	
	cout << "The sum of your fractions is ";
	displayFraction(yourFraction + yourSecondFraction);

	cout << "The product of your fractions is ";
	displayFraction(yourFraction * yourSecondFraction);

	// ################### Testing copy constructor ################################
	Fraction copyFraction = yourSecondFraction;
	cout << "Your copy fraction is ";
	displayFraction(copyFraction);
	return 0;
}
