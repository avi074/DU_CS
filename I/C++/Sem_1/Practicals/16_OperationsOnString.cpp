// comment about your program
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
// declaring macors
#define s_vowels(v) v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u'
#define c_vowels(v) v == 'A' || v == 'E' || v == 'I' || v == 'O' || v == 'U'
void showAdd(char * p) // showing addresses of each element
{
	/* if you want to show char pointer's pointing address 
		you have to convert it to a void pointer.*/
	cout << "\n\n\t Word\t\t Address \n";
	while(*p != '\0')
	{
		cout << "\n\t  "<< *p  << "\t   \t" << static_cast<void*>(p);
		p++;
	}
}
void withoutCat(string &s) // concatenating without strcat() 
{
	string s1;
	cin.ignore();
	cout << "\n\n Enter another string to concatenate : ";
	getline(cin, s1);
	s += s1;
	cout << "\n Your new string is : " << s << endl;
}
void withCat(string &s)	// concatenating without strcat()
{
	char ch[100];
	string s1;
	cin.ignore();
	cout << "\n\n Enter another string to concatenate : ";
	getline(cin,s1);
	strncpy(ch,s.c_str(),s.length());
	strcat(ch, s1.c_str());
	s = ch;
	cout << "\n Your new string is : " << s << endl;
}
void CompareStr(string s) // compare two strings
{
	string s1;
	short int c;
	cin.ignore();
	cout << "\n\n Enter another string to compare : ";
	getline(cin, s1);
	c = s.compare(s1);
	c == 0 ? cout <<"\n\t Same strings.\n" : cout <<"\n\t Unequal strings.\n";		
}
void CalcLen(char *s) // calculating length of string
{
	int len = 0;
	while(*s != '\0')
	{
		len++;
		s++;
	}
	cout << "\n\n Length of the String is : " <<  len << " charcters.\n";
}
void convrt_Upper(string &s) // change characters to upper case
{	
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] >= 97 && s[i] <= 122)
			s[i] -= 32;
	}
	cout << "\n\n Your new string is : " << s << endl;
}
void convrt_Lower(string &s)	// change characters to lower case
{
	
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] >= 65 && s[i] <= 90)
			s[i] +=  32;
	}
	cout << "\n\n Your new string is : " << s << endl;
}
void CalcVowel(string s) // calculating no. of vowels
{
	int n = 0;
	for(int i = 0; i < s.size(); i++)
		if(s_vowels(s[i]) || c_vowels(s[i]))
			n++;
	cout << "\n\n Total vowels used in string : " << n << endl;
}
void RevStr(string &s) // reversing the string
{
	char tmp;
	for(int i = 0, j = s.size() - 1; i < j; i++, j--)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
	cout << "\n\n Your reversed string is : " << s << endl;
}
int main()
{
	string str;
	char choice;
	cout << "\n\t\t\t\t\t Practical 16";
	cout << "\n\t\t\t\t    Operations on String  " << endl;
	cout << "\n Enter the string : ";
	getline(cin, str);
	do
	{
		cout << "\n =====================================================================";
		cout << "\n\n Choose an option : \n"
			 << "\n\t 1. Show address of each character in string "
			 << "\n\t 2. Concatenate two strings without using strcat() function "
			 << "\n\t 3. Concatenate two strings using strcat() function "
			 << "\n\t 4. Compare two strings "
			 << "\n\t 5. Calculate length of string "
			 << "\n\t 6. Convert all lowercase characters to uppercase"
			 << "\n\t 7. Convert all uppercase characters to lowercase "
			 << "\n\t 8. Calculate no. of vowels "
			 << "\n\t 9. Reverse the string \n\n";

		cout << " Enter your choice (0 for quit) :-  ";
		cin >> choice;
		cout << "\n =====================================================================";
		switch (choice)
		{			
		case '1':
			cout << "\n\n\t Showing address of each character in string...";
			showAdd(&str[0]);
			break;
			
		case '2':
			cout << "\n\n\t Concatenating without using strcat() function ";
			withoutCat(str);
			break;
			
		case '3':
			cout << "\n\n\t Concatenating using strcat() function ";
			withCat(str);
			break;
			
		case '4':
			cout << "\n\n\t Comparing two strings...";
			CompareStr(str);
			break;
			
		case '5':
			cout << "\n\n\t Calculating length of string...";
			CalcLen(&str[0]);
			break;
			
		case '6':
			cout << "\n\n\t Converting all lowercase characters to uppercase...";
			convrt_Upper(str);
			break;
			
		case '7':
			cout << "\n\n\t Converting all uppercase characters to lowercase...";
			convrt_Lower(str);
			break;
			
		case '8':
			cout << "\n\n\t Calculating number of vowels...";
			CalcVowel(str);
			break;
			
		case '9':
			cout << "\n\n\t Reversing the string...";
			RevStr(str);
			break;
			
		default:
			if(choice != '0')
				cout << "\n invalid input" << endl;
		}
	} while(choice != '0');
}
