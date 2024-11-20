// This program calculates  the sum of first n terms of the series
// S = 1 - 2 + 3 -4 +.......
#include <iostream>
using namespace std;
int main()
{
	int num , sum = 1;
	cout << "\n\t\t Practical 4 \n";
	cout << "\n This program calculates  the sum of first n terms of the series.";
	cout << "\n\n\t S = 1 - 2 + 3 - 4 +.......";
	
	cout << "\n\n How many terms of the series do you want to calculate : ";
	cin >> num;
	
	if(num < 1)
		cout << "\n Sum is none." << endl;
		
	else
	{
		num % 2 == 0 ? sum = -num/2 : sum = (num+1)/2;
		cout << "\n Sum of first " << num << " terms of series is : " << sum << endl;
	}	
}
