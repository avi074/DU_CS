#include <iostream>
using namespace std;

int factCalc(int num)
{
	if (num == 0 || num == 1)
		return 1;	
	else
		return (num * (factCalc(num - 1)));
}

void factor(const int& n, int i = 1)
{
	if(i > n/2){
		cout << n;
		return;
	}
	else if(n % i == 0)
		cout << i << '\t';
	factor(n,i+1);
}

int main()
{
	long factorial = 1;
	short int choice,num;

	cout << "\n\t Practical 11 \n  Factorial & Factor calculator \n\n";
	cout << " Enter a number :  ";
	cin >> num;

	if(num)
	{

		cout << "\n From which process you want to calculate  : \n 1. Using recursion \n 2. Using iterator (loops)";
		cout << "\n\n Enter your choice :  ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\n\n\t Using Recursion....\n";
			cout << "\nFactor of " << num << "\t: ";
			factor(num);
			cout << "\nFactorial of " << num << "  : " << factCalc(num);
			break;

		case 2:
			cout << "\n\n\t Using Iterator (Loops)";
			cout << "\nFactor of " << num << "\t: ";
			for (int i = 1; i <= num; i++)
			{
				factorial *= i;
				if(num % i == 0)
					cout << i <<'\t';
			}
			cout << "\nFactorial of " << num << "  : " << factorial;
			break;

		default:
			cout << "\n\n invalid input";
		}
	}
	else
		cout << "\n Please enter a positive number !!!";
	cout << endl;
}
