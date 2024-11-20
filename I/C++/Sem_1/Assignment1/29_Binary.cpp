/*****************************************************************************
comment about the program
*****************************************************************************/
#include <iostream>
//for extra headers
using namespace std;
//for more functions
int main()
{
	int num;
	long long int convrt = 0 , j = 1;
	cout << "\n This program prints the binary number equivalent to a positive number.";
	do{
		cout << "\n\n Enter a number that's binary do you want to know : ";
		cin >> num;
		if(num < 0)
			cout << "\n Please enter a positive number. \n";
	}while(num < 0);
	
	for(int i = num; i != 0 ; i /= 2 , j *= 10)
		convrt += (i % 2) * j; 
	
	cout << "\n Binary of " << num << " is : " << convrt << endl;
}
