/*****************************************************************************
comment about the program
*****************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

void file_(string f)
{
	fstream file;
	char ch;
	bool v = false;
	// opening file
	file.open(f.c_str(), ios::out | ios::in | ios::binary);
	// checking errors.
	if(file.fail())
	{
		cerr << "\n Error in opening file.";
		cout << "\n Please enter a right name or right path. \n";
		return;
	}
	// loop run until we get the end of file.
	while(!file.eof())
	{
		file.get(ch);
		if(ch == ':' || ch ==',')
		{
			ch = '#';
			v = true;
		}
	}
	cout << "\n Your data has been replaced successfully." << endl;
	// closing the files
	file.close();
}

int main()
{
	string filename;
	
	cout << "\n This program converts vowels into # that located in the file.";	
	cout << "\n\n Enter the file name with extension or file path : \n ";
	getline(cin, filename);
	file_(filename);
}
