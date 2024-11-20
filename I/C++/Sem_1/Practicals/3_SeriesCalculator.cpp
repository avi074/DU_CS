// This program calculates  the sum of first n terms of the series
// S = 1 + 1/2 + 1/3 +.......
#include <iostream>
using namespace std;
int main()
{
	int num; 
	float sum = 1;	
	cout << "\n\t\t Practical 3 \n";
	cout << "\n This program calculates the sum of first n terms of the series.\n";
	cout << "\n\t S = 1 + 1/2 + 1/3 +.......\n\n";
	cout << " How many terms of the series do you want to calculate : ";
	cin>> num;
	if(num < 1)
		cout << "\n Sum is none." << endl;
	else 
	{
		for (int i=2; i <= num;i++)
			sum += 1.0 / i;			
		cout << "\n Sum of the first " << num << " terms of series : " << sum << endl;
	} 
}  
