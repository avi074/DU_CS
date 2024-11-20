#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct students
{
	int roll;
	char name[25];
	char Class[20];
	short year;
	short marks;	
};

int main()
{
	ifstream f;
	string s;
	short i = 0;
	students stud;
	bool stop = true;
	
	cout << "\n\t\t\t Practical 26 \n";
	cout << "\n This Program shows the data of the students which is taken in Q.25. \n";
	f.open("record.dat", ios::binary | ios::in);
	if(!f)
	{
		cerr << "\n\n Error occurred in opening file. \n";
		return 0;
	}
	cout << "\n "<< setw(10) << " Roll No.\t\tName\t\tClass\t\t Year\t\tMarks \n";
	
	while(f.read((char *)&stud, sizeof(stud)))
	{
		cout << "\n "<< setw(7) << stud.roll << setw(20) << stud.name << setw(15) << stud.Class << setw(18) << stud.year << setw(15) <<  stud.marks;
	}
	f.close();
}
