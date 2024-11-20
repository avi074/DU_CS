/*****************************************************************************
comment about the program
*****************************************************************************/
#include <iostream>
//for extra headers
using namespace std;
//for more functions
int main()
{
	int year;
	cout << "\n This program tells you that entered year is a leap year or not.";
	do
	{
		cout << "\n\n Enter a year : ";
		cin >> year;
		if(year < 0)
			cout << "\n Year can not be negative." << endl;		
	}while(year < 0);
	
	if(year % 4)
		cout << "\n " << year << " is not a leap year." << endl;
	else
		cout << "\n " << year << " is a leap year." << endl;
}
