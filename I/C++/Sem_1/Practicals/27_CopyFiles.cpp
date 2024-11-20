#include <iostream>
#include <fstream>
using namespace std;
void copy_(string f1, string f2)
{
	char s;
	ifstream rf;
	ofstream sf;
	bool ret = false;
	rf.open(f1.c_str());
	if(!rf)
	{
		cerr << "\n\n Error occurred in opening file . \n";
		return;
	}
	sf.open(f2.c_str());
	if(!sf)
	{
		cerr << "\n\n Error occurred in creating file . \n";
		return;
	}
	cout << "\n Files have been found  successfully. \n";
	while(!rf.eof())
	{
		rf.get(s);
		if(rf.bad())
		{
			cerr << "\n Error occurred in reading file. \n";
			ret = true;
			break;
		}
		if(s == ':' || s == ',')
			s = ' ';
		sf.put(s);
		}
		if(sf.bad())
		{
			cerr << "\n Error occurred in writing file. \n";
			ret = true;
			break;
		}
	}
	if(ret)
		return;
	cout << "\n File have been copied successfully. \n";	
}

int main()
{
	string s1,s2;
	cout << "\n\t\t\t Practical 27 ";
	cout << "\n\n This program copies one file's data to another file after removing all white spaces.\n";
	cout << "\n Enter the filename(with extension) / path from which you want to copy your data : \n  ";
	cin >> s1;
	cout << "\n Enter the filename(with extension) / path in which you want to store your data : \n  ";
	cin >> s2;
	copy_(s1,s2);
}
