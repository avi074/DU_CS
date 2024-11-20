/***************************************************************
 File Name : - 19_FactorialCalculator.cpp
 Date Created :- 20-Dec-2020
 
 Description :-
 		This program calculates factorial of given input.
 		input = 4
 		process = 4*3*2*1
 		output = 24 ( Because 4! = 24)
***************************************************************/
#include <iostream>
using namespace std;
double factCalc(int);
int main()
{
	double factorial = 1;
	short int choice,num;
	cout << "\n\t Factorial Calculator \n\n";
	cout << " Enter a number :  ";
	cin >> num;
	cout << "\n From which process you want to calculate  : \n 1. Using recursion \n 2. Using iterator (loops)";
	cout << "\n\n Enter your choice :  ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "\n\n\t Using Recursion....";
		cout << "\n\n " << num << "!  =  " << factCalc(num);
		break;
	case 2:
		cout << "\n\n\t Using Iterator (Loops)";
		if (num == 0 || num == 1)
			cout << "\n\n " << num << "! =  1 ";
		else
		{
			for (int i = 1; i <= num; i++)
			{
				factorial *= i;
			}
			cout.precision(0);
			cout << "\n\n " << num  << fixed<< "!  =  " << factorial;
		}
		break;
	default:
		cout << "\n\n invalid input";
	}
}

double factCalc(int num)
{
	if (num == 0 || num == 1)
		return 1;	
	else
		return (num * (factCalc(num - 1)));
}
