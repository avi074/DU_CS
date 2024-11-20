/*****************************************************************************
This Program prints an star bow.
input- 3
output- 
			*
			 **
			  ***
			 **
			*
*****************************************************************************/
#include <iostream>
//for extra headers
using namespace std;
//for more functions
int main()
{
	short int num;
	bool revLoop = false;
	cout << "\n\t \" Star Bow \" ";
	do
	{
		cout << "\n\n How many stars in a line do you want :  ";
		cin >> num;
		if(num <= 0)
			cout << "\n Enter a positive number. \n";
	}while(num <= 0);
	
	cout << endl;
	// revloop=true hone pr loop reverse hoga
	for(int i = 1 ;i != 0; )
	{ 
		cout << "\t";
		for(int j = 1; j <= i; j++)
			cout << " ";
		for(int k = 0; k < i; k++)
			cout << "*";
		cout << endl;
		if(i == num)
			revLoop = true;
		revLoop ? i-- : i++;		
	}
}
