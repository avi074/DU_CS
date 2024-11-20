/*****************************************************************************
comment about the program
*****************************************************************************/
#include <iostream>
using namespace std;
#define find(s,a,b) s == a || s == b
int main()
{
	char ch[] = {'a','A','e','E','i','I','o','O','u','U'};
	short int c[5] = {0};
	string str;
	cout << "\n\t String Vowels Counter \n";
	cout << "\n Enter the string : ";
	getline(cin,str);
	for(int i = 0; str[i] != '\0'; i++)
	{
		for(int j = 0, k = 0; j < 10; j += 2, k++)
			if(find(str[i],ch[j],ch[j+1]))
				c[k]++;	
	}
	cout << "\n\t Vowel : Time occurs ";
	for(int i = 0 , j = 0; i < 5; i++ , j += 2)
	{
		if(c[i])
			cout << "\n\t   " << ch[j] << "   :   " << c[i];
	}	
}
