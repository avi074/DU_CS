/*********************************************************************************
 File name		:- Palindrome_Checker.cpp
 Date(Created)  :- 13-Dec-2020
 Description 	:- 
 					This program checks that input data is a palindrome or not. 
	 	Palindrome is a term that shows the equality of data with it's reversed form.
	 
	 eg. - 101 is a palindrome because it's reversed form is also 101.
	 	 'saw' is not a palindrome because it's reversed form is 'was'.	 	   
**********************************************************************************/
#include <iostream>
using namespace std;
int main()
{
	string str;
	bool equal = false;
	cout << "\n\t\t   Practical 5 \n\t\t Palindrome Checker\n\n";
	cout << " Enter your word / number : ";
	cin >> str;
	for(int i = 0, j = str.length() - 1; i < j; i++, j--)
	{
		equal = (str[i] == str[j]);
		if(!equal)
			break;
	}
	if (equal)
		cout << "\n  " << str << " is a Palindrome." << endl;
	else
		cout << "\n  " << str << " is not a Palindrome." << endl;
}
