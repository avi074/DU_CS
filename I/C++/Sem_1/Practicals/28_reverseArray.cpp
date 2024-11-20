/*****************************************************************************
comment about the program
*****************************************************************************/
#include <iostream>
//for extra headers
using namespace std;
int size;
void reverse(int *n)
{
	int l = size;
	for(int i = 0, j = size - 1; i < j; i++ ,j--)
	{
		n[i] = n[i] + n[j];
		n[j] = n[i] - n[j];
		n[i] = n[i] - n[j];
	}	
}
int main()
{
	int num[20];	
	cout << "\n\t\t Array Reverser \n";
	cout << "\n How many values do you want to enter : ";
	cin >> size;
	cout << "\n\t S.N. \t Elements \n\n";
	for(int i = 0; i < size; i++)
	{
		cout << "\t  " << i+1 << " \t  ";
		cin >> num[i];
	}
	reverse(num);
	cout << "\n Your new array is :";
	cout << "\n\n\t S.N. \t Elements \n\n";
	for(int i = 0; i < size; i++)
		cout << "\t  " << i+1 << " \t  " << num[i] << endl;	
}
