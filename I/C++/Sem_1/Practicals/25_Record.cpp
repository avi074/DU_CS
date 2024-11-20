#include <iostream>
#include <fstream>
using namespace std;

struct students
{
	int roll;
	char name[25];
	char Class[20];
	short year;
	short marks;
	// function
	void record(int, ofstream&);	
};

void students::record(int n, ofstream &f)
{
	string s1;
	bool error = false;
	
	cout << "\n\n Enter the data of students.... ";
	for(int i = 0; i < n; i++)
	{
		cout << "\n\n Student  " << i+1 << " : \n";
		cout << "\n Roll no.    :  ";
		cin >> roll;
		cin.ignore();
		cout << " Name        :  ";
		cin.getline(name,25);
		cout << " Class       :  ";
		cin.getline(Class, 20);
		cout << " Year        :  ";
		cin >> year;
		cout << " Total Marks :  ";
		cin >> marks;
		
		f.write((char *)this, sizeof(*this));
		if(f.bad())
		{
			cerr << "\n\n Error in writing file. \n";
			error = true;
			break;
		}			
	}
	
	if(error)
		return;
	else
		cout << "\n\n All the data have been saved in the record.dat file." << endl;	
}

int main()
{
	short num;
	ofstream f1;
	students stud;
	
	cout << "\n\t\t\t Practical 25 ";
	cout << "\n\t\t\tStudents Record";
	cout << "\n\n How many students' data do you want to enter  : ";
	cin >> num;
	//opening the file
	f1.open("record.dat", ios::binary | ios::out);
	if(!f1)
		cerr << "\n\n Error in creating file.";
	else
		stud.record(num , f1);
	f1.close();
}
