/*****************************************************************************
comment about the program
*****************************************************************************/
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

ofstream p; // global variable
void file_(string str)
{
	p << str << " ";
	if(p.bad())
	{
		cerr << "\n Error in writing file." << endl;
		return;
	}
}

void find_(string f)
{
	int i = 0 , j = f.size() - 1;
	bool palindrom = false;

	for(; i <= j; i++, j--)
	{
		palindrom = (f[i] == f[j]);
		if(!palindrom)
			break;
	}
	if(palindrom)
		file_(f);
}

void find_sum(string f, int &n)
{
	int carry = 0;
	stringstream s;
	s << f;
	s >> carry;
	n += carry;
}

int main(int c, char * arg[])
{
	int sum = 0;
	if(c == 1)
		cout << "\n There is no arguments.\n";
	else
	{
		p.open("Palindrome.txt");	
		if(p.fail())
		{
			cerr << "\n Error in creating file." << endl;
			return 0;
		}
		for(int i = 1; i < c; i++)
		{
			find_(arg[i]);
			find_sum(arg[i], sum);
		}	
	}
	cout << "\n Palindromes have been saved in Palindrome.txt file.";
	p.close();
	cout << "\n The sum of the numbers is : " << sum;
}
