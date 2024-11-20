/*****************************************************************************
comment about the program
*****************************************************************************/
#include <iostream>
//for extra headers
using namespace std;
//for more functions
int main()
{
	short int dd[3] , mm[3] , yy[3];
	bool  non_valid = false;
	cout << "\n\t\t Age Calculator \n";
	do{
		cout << "\n Enter your Date of Birth (eg - dd mm yyyy) :  ";
		cin >> dd[0] >> mm[0] >> yy[0];
		cout << "\n Enter the date till you want to calculate  :  ";
		cin >> dd[1] >> mm[1] >> yy[1];
		for(int i = 0 ; i < 2;i++)
		{
			if(dd[i] < 1 || dd[i] > 32)
				non_valid = true;
			else if(mm[i] < 1 || mm[i] > 13)
				non_valid = true;
			else if (yy[i] < 0)
				non_valid = true;
			else
				non_valid = false;	
			if(mm[i] == 2)
			{
				if(yy[i] % 4 == 0)
					non_valid = (dd[i] > 29);
				else
					non_valid = (dd[i] > 28);
			}				
			if(non_valid)
				break;
		}				
		if(non_valid || yy[1] < yy[0])
			cerr << "\n Please enter the correct dates. \n";
	}while(non_valid || yy[1] < yy[0]);
	// calculating age
	dd[2] = dd[1] - dd[0];
	mm[2] = mm[1] - mm[0];
	yy[2] = yy[1] - yy[0];
	
	if(dd[2] < 0)
	{
		dd[2] = 31 + dd[2];
		if(mm[2] < 0)
			mm[2] = 11 + mm[2];
		else if(mm[2] >= 0)
			mm[2] = 11 - mm[2];
		yy[2]--;
	}
	else if(mm[2] < 0)
	{
		mm[2] += 12;
		yy[2]--;
	}
	cout << "\n Your age till " << dd[1] << "-" << mm[1] << "-" << yy[1] << " will be " << yy[2] << " years " << mm[2] 
		 << " months " << dd[2] << " days. " << endl;
}
