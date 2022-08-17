#include "SignedFraction.h"
#include<vector>
#include<random>
#include <iostream>

using namespace std;

//this is a helper function used with reduceFraction
//Given two positive number, it will return their greatest common
//divisor
unsigned int gcd(unsigned int first_number, unsigned int
	second_number)
{
	unsigned int gcd = 1;
	for (unsigned int i = 1; i <= first_number && i <= second_number;
		i++)
	{
		if (first_number % i == 0 && second_number % i == 0)
			gcd = i;
	}//end for
	return gcd;
}//end gcd


//This function reduces a fraction e.g. 2/4 will become 1/2. It can be
//used in diferent places.
//In this tester it is used in the function dispalying elements of a
//vector of signed fractions.
void reduceFraction(SignedFraction& fr)
{
	unsigned int greatestCommonDiviosor = gcd(fr.getNumerator(),
		fr.getDenominator());
	fr.setNumerator(fr.getNumerator() / greatestCommonDiviosor);
	fr.setDenominator(fr.getDenominator() / greatestCommonDiviosor);
}//reduceFraction


//a Function to display a vector of Fraction object items.
void displayVectorOfSignedFractionObjects(std::vector<SignedFraction>&
	fracVec) {
	for (auto& item : fracVec) {
		reduceFraction(item);
		cout << item << "\t";
	}
}//displayVectorOfSignedFractionObjects


//This is a function to randomly generate numbers for numerator and
//denominator.We keep flipping the sign
//to get both positive and negative fractions


void generateVectorOfSignedFractionObjects(std::vector<SignedFraction>&
	fracVec, unsigned int numberOfFractions) {
	unsigned int num, denom;
	bool sign = false;
	for (size_t i = 0; i < numberOfFractions; i++, sign = !sign) {
		//generate random num and denom
		num = rand() % 10 + 1; //here trying to keep numerator between 1 and 10
			denom = rand() % 15 + 1;// and denomirator between 1 and 15 //You can pick any numbers you wish in a future use.
		SignedFraction temp(num, denom, sign);
		fracVec.push_back(temp);
	}
}

//Here I am borrowing selection sort from the text book page 496
void
sortVectorOfSignedFractionObjects_selection(std::vector<SignedFraction
>& v) {
	int minIndex;
	SignedFraction minValue;
	for (int start = 0; start < (v.size() - 1); start++)
	{
		minIndex = start;
		minValue = v.at(start);
		for (int index = start + 1; index < v.size(); index++)
		{
			if (v.at(index) < minValue)
			{
				minValue = v[index];
				minIndex = index;
			}
		}
		std::swap(v[minIndex], v[start]);
	}
}

// Optional sum of vector function
SignedFraction sumOfVector(const vector<SignedFraction>& v) {
	SignedFraction total;
	for (const SignedFraction& item : v) {
	total = total + item;
	}
	reduceFraction(total);
	return total;

}

//write a function based on binary search in the book page 468. Notice here we want to return a bool
//true for found, and false for not found
bool binarySearchVectorOfFraction(const std::vector<SignedFraction>&
	v, SignedFraction searchedItem)
{
	//your code goes here
	bool found = false;
	int first = 0, last = (v.size()-1), middle;
	reduceFraction(searchedItem);
	while (first <= last && !found) {
		middle = (first + last) / 2;
		if (searchedItem == v.at(middle)) {
			found = true;
		}
		else if (searchedItem < v.at(middle)) {
			last = middle - 1;
		}
		else if (searchedItem > v[middle]) {
			first = middle + 1;
		}
	}

	return found;
} 
int main() {
	srand(time(NULL));
	std::vector<SignedFraction> fractions;
	int size = 5;
	generateVectorOfSignedFractionObjects(fractions, size);
	displayVectorOfSignedFractionObjects(fractions);
	sortVectorOfSignedFractionObjects_selection(fractions);
	std::cout << "\nAfter sorting...\n";
	displayVectorOfSignedFractionObjects(fractions);
	//variables needed to test search function.
	unsigned int nume{ 1 }, denom{ 1 };
	bool signedd{ false };
	std::cout << "\nSearching for an item...\n";
	std::cout << "\nPlease enter the numerator and denominator of your fraction: ";
	std::cin >> nume >> denom;
	std::cout << "\nIs you fraction signed 1 for no, 0 for yes \n";
	std::cin >> signedd;
	SignedFraction searchedItem(nume, denom, signedd);
	reduceFraction(searchedItem);
	if (binarySearchVectorOfFraction(fractions, searchedItem))
		std::cout << "Your fraction " << searchedItem << " was found in the vector \n";
	else
		std::cout << "Your fraction " << searchedItem << " was not found in the vector \n";

	SignedFraction fr(1, 2, true), frr(1, 3, false);
	// Testing less than operator
	bool test = fr < frr;
	cout << endl << test << endl;	

	// Testing greater than operator
	test = fr > frr;
	cout << endl << test << endl;

	// Testing multiplication and insertion operator
	std::cout << "\nTesting multiplication...\n";
	SignedFraction fs = frr * fr;
	std::cout << frr << " * " << fr << " = " << fs << endl;

	// Testing the sum of vector function
	SignedFraction sum = sumOfVector(fractions);
	cout << "The total sum of the fractions vector is " << sum << endl;

	return 0;
}