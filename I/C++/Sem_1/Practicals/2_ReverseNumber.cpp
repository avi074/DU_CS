/***********************************************************************************************
 File Name :- 2_ReverseNumber.cpp
 Creation Date :-	13/01/2021
 
 Description :-		
 			This program reverses the sequence of given number.
 			
 			input = 1234
 			output = 4321			  			
 *********************************************************************************************/
#include <iostream>

using namespace std;
int main()
{
	long int num, convrtnum = 0;
	bool last = true;
	cout << "\n\t\t Practical 2 \n";
	cout << "\n This program reverses the given number.\n\n";
	cout << " Enter any Number : ";
	cin >> num;	
	cout << "\n reverse of " << num << " is : ";
	for(long i = num; i != 0; i /= 10)
	{
		convrtnum = convrtnum * 10 + (i % 10);
		if(i % 10 == 0)
		{
			if(last)
				cout << "0";
		}
		else
			last = false;	
	}	
	cout << convrtnum << endl;
}
