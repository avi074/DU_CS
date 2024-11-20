/****************************************************************************************
 File Name :- 7_FactorCalculator.cpp
 Date :- 13-01-2020
 
 Description :- 
 			This Program tells us the factors of given Number.
 			
 			input = 4 
 			output = 1,2,4 is the factors of 4.
 ***************************************************************************************/
#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "\n\t\t   Practical 7  " << endl;
    cout << "\n\t\t Factor Calculator  \n";
    cout << "\n Enter your number : ";
    cin >> num;
    
    if (num == 0) 
		cout << "\n Fator of 0 is all the numbers." << endl;
		
    else
	{
    	cout << "\n Factors of " << num << " is :  1 , " ;
    	for (int i = 2; i <= num/2 ; i++)
   	 	{
        	int rem = num % i;
        	if(rem == 0)
				cout << i << " , " ;			
    	}
    	cout << num << endl;
	}
}
