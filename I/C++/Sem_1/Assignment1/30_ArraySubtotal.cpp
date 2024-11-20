/*****************************************************************************
comment about the program
*****************************************************************************/
#include <iostream>

//for extra headers
using namespace std;
void subtotal(int *len , float *num)
{
	float sum = 0;
	cout << "\n\n Your Array after subtotaling  : " << endl;
	cout << "\n\t S.N. \t Elements \n";
	for(int i = 0; i < *len ; i++)
	{
		sum += num[i];
		num[i] = sum;
		cout << "\t " << i+1 << "\t  " << num[i] <<endl; 
	}	
}

int main()
{
	int size = 0;
	float num[20];
	cout << "\n\t This program will change the number to the sum of their left ended numbers.";
	do
	{
		cout << "\n\n How many numbers do you want to enter : ";
		cin >> size;
				
		if(size <= 0)
			cerr << "\n Enter a positive number not 0 or any negative. \n";	
					
	}while (size <= 0);
	
	cout << "\n Enter the numbers : ";
	cout << "\t S.N. \t Elements \n";
	for(int i = 0 ; i < size; i++)
	{
		cout << " \t\t\t   " << i+1 << "\t   ";
		cin >> num[i]; 
	}
	subtotal(&size , num);
}
