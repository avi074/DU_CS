#include <iostream>
using namespace std;
long Fibonacci(int);
int main()
{
	int choice , num;
	long f1 = 0, f2 = 1, f3; // f1,f2 & f3 are function of Fibonacci series
	cout << "\n\t\t\t Practical 18\n\t\t Fibonacci Series Displayer \n\n";
	cout << " Enter the term till you want to display  :  ";
	cin >> num;
	if (num <= 0)
		cout << "\n Please don't enter any negative number or 0\n\n";
	cout << "\n What process would you like : \n 1. Using recursion \n 2. Using iteration";
	cout << "\n\n Enter your choice :  ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "\n Fibonacci Series till nth term is : \n\n  ";
		for(int i = 1; i <= num; i++)
			cout << Fibonacci(i) << "\t";
		break;
	case 2:
		cout << "\n Fibonacci Series till nth term is : \n\n  " << f1 << "\t" << f2;
		for (int i = 3; i <= num; i++)
		{
			f3 = f1 + f2;
			cout << "\t" << f3;
			f1 = f2;
			f2 = f3;
		}
		break;
	default:
		cout << "\n\n invalid input";
	}
}
long Fibonacci(int n)
{
	long sum = 0;
	long static num[4] = {2,1,1,0};
	
	if (n == num[0])
		return num[1];
	if (n == num[2])
		return num[3];
	else
	{
		sum = (Fibonacci(n - 2) + Fibonacci(n - 1));
		num[0] = n;
		num[2]++;
		num[3] = num[1];
		num[1] = sum;
		return sum;
	}	
}
