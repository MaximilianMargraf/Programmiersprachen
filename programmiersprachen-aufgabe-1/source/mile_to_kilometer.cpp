#include <iostream>

int main()
{
	// Input
	std::cout<<"Bitte geben sie die Meilen ein: ";
	double miles;
	std::cin >> miles;

	// Output
	std::cout<<"Dies sind "<< miles * 1.609344 << " Kilometer.\n";

	return 0;
}