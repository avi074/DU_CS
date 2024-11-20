/*****************************************************************************
	Now this program has only 1 defect.
	if I input 2 similar words in a string and i enter only 1 in char it will 
	give me a wrong result.
	
	input :- 1st - Hyy
			 2nd - hiy
	output :- these are anagrams.
	solution :- You can check vice versa or both two strings. 
*****************************************************************************/
#include <iostream>
//for extra headers
using namespace std;

int rmv_(string &s)
{
	int _n = 0;
	for(int i = 0; s[i] != '\0'; i++)
	{
		if(s[i] == ' ')
		{
			for(int j = i; s[j] != '\0' ;j++)
				s[j] = s[j+1];
			_n--;
		}			
	}
	return (s.length() + _n);
}

int main()
{
	string str , str1;
	short int len = 0 ,len1 = 0;
	bool anag;
	cout << "\n This program tells you that entered two strings are anagrams or not.";
	cout << "\n\n Enter First string :  ";
	getline(cin , str);
	cout << "\n Enter Second string :  ";
	getline(cin , str1);
	// after removing all spaces
	len = rmv_(str);
	len1 = rmv_(str1);
	
	if(len != len1)
		cout << "\n These strings are not anagrams." << endl;
	else
	{
		for(int i = 0 ; i < len; i++)
		{
			for(int j = 0; j < len; j++)
			{
				anag = (str[i] == str1[j]);
				if(anag)
					break;				
			}
		 	if(!anag)
				break;
				 
			for(int k = 0 ; k < len; k++)
			{
				anag = (str1[i] == str[k]);
				if(anag)
					break;				
			}
			if(!anag)
				break;
		}
		if(anag)
			cout << "\n These strings are anagrams." << endl;
		else
			cout << "\n These strings are not anagrams." << endl;
	}
}
