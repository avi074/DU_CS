/*****************************************************************************
comment about the program
*****************************************************************************/
#include <iostream>
#include <fstream>
//for extra headers
using namespace std;

void copy_file(ifstream &f, ofstream &o, bool &c)
{
	string store;
	while(!f.eof())
	{
		getline(f, store);
		o << store << endl;
		if(o.bad() || f.bad())
		{
			c = false;
			cerr << "\n Error in reading / writing files.\n";
			break;
		}
	}
}

void file_join(ifstream &file1, ifstream &file2)
{
	string s3;
	bool done = true;;
	ofstream Data;
	cout << "\n Enter the file name (with extention) in which you want to save your data : \n ";
	getline(cin, s3);
	// open final file
	Data.open(s3.c_str());
	if(!Data)
	{
		cerr << "\n Error in creating file. \n";
		Data.close();
		return;
	}
	else
	{
		copy_file(file1, Data, done);
		if(done)
			copy_file(file2, Data, done);
	}
	if(done)
		cout << "\n Flie data transfer has been done.\n";	
}

int main()
{
	ifstream f1,f2;
	string s1,s2;
	cout << "\n This program concatenate two files' data into a file.\n";
	// prompt files
	cout << "\n Enter your first file name with extention or path : \n ";
	getline(cin, s1);
	cout << "\n Enter your second file name with extention or path : \n ";
	getline(cin, s2);
	// checking files
	f1.open(s1.c_str());
	f2.open(s2.c_str());
	if(!f1 || !f2)
	{
		cerr << "\n Error in opening files.\n Please give right path or name.\n";
		f1.close();
		f2.close();
		return 0;
	}
	else
	{
		cout << "\n Files have been found successfully.\n";
		file_join(f1 , f2);
	}		
	f1.close();
	f2.close();	
}
