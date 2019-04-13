#include <iostream>

// check for smallest number, which is dividable for all numbers in given range
int smallestDividable(unsigned int a, int b)
{
	bool countFalse = false;
	unsigned int smallestNumber = b - 1;

	while (countFalse != true)
	{
		// reset for each number tested
		countFalse = true;

		// after checking for every number in range, check for next number
		smallestNumber += 1; 

		// from a to b check if the modulo returns 0
		for (int i = a; i <= b; i++)
		{
			// if it does not return 0, we can directly jump to the next number
			// if it does return 0, we need to check all other numbers
			if (smallestNumber % i != 0)
			{
				countFalse = false;
				break;
			}
		}
	}

	return smallestNumber;
}


int main()
{
	int sD = smallestDividable(1, 20);
	std::cout <<"The smallest number dividable by all numbers from 1 to 20 is: " << sD << "\n";
	return 0;
}