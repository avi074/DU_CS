/*************************************************************************************************
 File Name :-	20_GCD_Calculator.cpp
 Date Created :- 25-12-2020
 
 Description :-
 			This program calculates the GCD (Greatest Common Divisor) of given two numbers.
 			Euclid Method is a fast process and finding factors is a long and slow process.
 			
 			input -> 16 48 
 			process -> simply you can use " Euclid Method " or you can find factors of given number.
 						Biggest common factor of given numbers is GCD. 
 						16 = 1,2,4,8, < 16 >
 						48 = 1,2,3,4,6,8,12, < 16 > ,24,48
 						GCD = Biggest common factor = 16 
 			output -> GCD(16,48) = 16 
 
 *************************************************************************************************/
#include <iostream>
using namespace std;
int GCD(int, int);
int main()
{
	int a, b,a1,gcd;
	short int choice; 
	cout << "\n\t\t GCD CALCULATOR \n\n";
	cout << " Enter two numbers (use space):  ";
	cin >> a >> b;
	cout << "\n Which process do you like : \n\n\t 1. With Recursion \n\t 2. Without Recursion \n\n";
	cout << " Enter your choice : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		gcd = GCD(a, b);
		if (gcd == 0)
			cout << "\n GCD (" << a << "," << b << ") = undefined" << endl;
		else
			cout << "\n GCD (" << a << "," << b << ") = " << gcd << endl;
		break;

	case 2:
		if (a == 0 && b == 0)
			cout << "\n GCD (" << a << "," << b << ") = undefined"<< endl;
		else
		{ // using simple logic of factor
			(a > b )? a1 = b : a1 = a; // loop has to work untill reach small number.
			for (int i = 1; i <= a1; i++)
			{
				int c = a % i; // factor of a when c = 0
				int d = b % i; // factor of b when d = 0
				if (c == 0 && d == 0 && c == d)
					gcd = i; // last common factor
			}
			cout << "\n GCD (" << a << " , " << b << ") = " << gcd<< endl;
		}
		break;

	default:
		cout << "\n\n invalid input"<< endl;
	}
}
int GCD(int a, int b)	  // 			Euclid Method
{						  // GCD(a,b) will be the last value of a after do while loop ends.
	if (a == 0 && b == 0) //	do{rem = a % b;
		return 0;		  // 		a = b;
	else if (a % b == 0)  //		b = rem; }while(rem != 0);
		return b;
	else if (b % a == 0)
		return a;
	else
	{
		if (a > b)
			return GCD(b, a % b);
		else
			return GCD(a, b % a);
	}
}
