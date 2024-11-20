/***********************************************************************************************
 File Name :- 6_PrimeNumbers.cpp
 Creation Date :-	13/01/2021
 
 Description :-		
 			This program checks that the input number is prime or not and it also generates 
 			prime numbers till 100.
			  			
 *********************************************************************************************/
#include <iostream>
// for extra headers
using namespace std;

void chk_printPrime(int num)
{
	int rem = 1; // rem = 1 so that for loop can run.
	bool prime = false;

	if (num == 2)
		cout << "\n 2 is a prime number." << endl;

	else if (num == 0 || num == 1 || (num % 2) == 0)
		cout << "\n " << num << " is not a prime number." << endl;

	else
	{
		for (int i = 3; rem != 0; i += 2)
		{
			rem = num % i;
			if (rem == 0)
				prime = (i == num);
		}

		if (prime)
			cout << "\n " << num << " is a prime number." << endl;
		else
			cout << "\n " << num << " is not a prime number." << endl;
	}

	cout << "\n\n Prime numbers till 100 :- \n\n";
	for (int i = 2; i < 100; i++) // generate prime numbers till 100
		for (int j = 2; j < 100; j++)
			if ((i % j) == 0)
			{
				if (j == i)
					cout << " " << j << "\t";
				break;
			}
}

int main()
{
	int num;
	cout << "\n\t\t Practical 6 \n";
	cout << "\n\t Prime Numbers Detector & generator " << endl;
	do
	{
		cout << "\n\n Enter a number : ";
		cin >> num;
		if (num < 0)
			cout << "\n Enter a positive number.\n";
	} while (num < 0);

	chk_printPrime(num);
	cout << endl;
}
