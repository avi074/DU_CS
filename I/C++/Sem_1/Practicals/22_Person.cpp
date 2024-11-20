#include <iostream>

using namespace std;
class person // Base Class
{
	string name, mob;
	int age;
	char gen;
public:
	virtual void set();
	virtual void print();
	~person(){}
};
person *p[5] = {NULL}, *p1[5] = {NULL};
int n = -1;
bool creat = false;
class teacher : public person // Derived Class 1
{
	int salary;
	string depart, id;	
public:
	teacher(){};
	virtual void set();
	virtual void print();
	~teacher(){}
};
class student : public person // Derived Class 2
{
	int roll;
	string course;
	float per;	
public:
	virtual void set();
	virtual void print();
	~student(){}
};
// functions
void create(char c)
{
	if(c == '1')
	{
		if(n == 1)
			p[0] = new teacher;
		else
		{
			for(int i = 0; i < n; i++)
				p[i] = new teacher;
		}
		cout << "\n Enter the details : \n";
		for(int i = 0 ; i < n; i++)
		{
			if(n == 1)
				p[i]->set();
			else
			{
				cout << "\n Teacher " << i+1 << " : ";
				p[i]->set();
			}
		}
	}
	else
	{
		if(n == 1)
			p1[0] = new student;
		else
		{
			for(int i = 0; i < n; i++)
				p1[i] = new student;
		}
		cout << "\n Enter the details : \n";
		for(int i = 0 ; i < n; i++)
		{
			if(n == 1)
				p1[i]->set();
			else
			{
				cout << "\n Student " << i+1 << " : ";
				p1[i]->set();
			}
		}
	}	
	creat = true;
}
void choose()
{
	char op;
	cout << "\n\t\t Creating the Objects";
	do
	{
		cout << "\n\n 1. Teacher \n 2. Student \n Which kind of object do you want to create : ";
		cin >> op;
		if(op != '1' && op != '2')
			cerr << "\n\n invalid input !!!";		
	}while(op != '1' && op != '2');
	cout << "\n How many objects do you want to create : ";
	cin >> n;
	create(op);
}
void print()
{
	if(creat)
	{
		cout << "\n\t\t Printing all details  \n";
		if(p[0] != NULL)
		{
			cout << "\n Teacher's Details : \n";
			for(int i = 0 ; i < n; i++)
			{
				if(n == 1 )
					p[i]->print();
				else
				{
					cout << "\n Teacher " << i+1 << " : \n";
					p[i]->print();
				}
			}
		}
		if(p1[0] != NULL)
		{
			cout << "\n Student's Details : \n";
			for(int i = 0; i < n; i++)
			{
				if(n == 1 )
					p1[i]->print();
				else
				{
					cout << "\n Student " << i+1 << " : \n";
					p1[i]->print();
				}
			}
		}
	}
	else
		cout << "\n Any objects have not been created yet. \n";
}
void del()
{
	if(creat)
	{
		if(p[0] != NULL)
		{
			for(int i = 0; i < n; i++)
				delete p[i];
		}
		if(p1[0] != NULL)
		{
			for(int i = 0; i < n; i++)
				delete p1[i];
		}
		creat = false;
		n = 0;
	}
	else
		cout << "\n Any objects have not been created yet. \n";
}
int main()
{
	char ch;
	do
	{
		system("cls");
		cout << "\n\t\t Practical 22 \n";
		cout << "\n ******************* Menu ****************** \n";
		cout << " 1. Create Objects \n 2. Display Details \n 3. Delete Objects \n 4. Quit ";
		cout << "\n\n Enter your choice : ";
		cin >> ch;
		cout << "\n ******************************************** ";
		switch(ch)
		{
			case '1':
				choose();
				break;
				
			case '2':
				print();
				break;
				
			case '3':
				if(creat)
					cout << "\n\t\t Deleting the objects ";
				del();
				if(n == 0)
				{
					cout << "\n\n The Objects have been deleted successfully.\n";
					n = -1;
				}
				break;
				
			case '4':
				if(creat)
					del();
				break;
				
			default:
				cout << "\n invalid input!!!";								
		}
		if(ch != '4')
		{
			cout << endl << endl;
			system("pause");
		}		
	}while(ch != '4');	
}
// Base Class Functions
void person::set()
{
	char ch;
	
	cin.sync();
	cout << "\n Enter the Name  : ";
	getline(cin, name);
	cout << " Enter your Age  : ";
	cin >> age;
	do
	{
		cout << " Enter your Gender (1. Male, 2. Female, 3. Trangender) : ";
		cin >> ch;
		switch(ch)
		{
			case '1':
				gen = 'M';
				break;
			case '2':
				gen = 'F';
				break;
			case '3':
				gen = 'T';
				break;
			default:
				cout << "\n\n Invalid input. \n";
		}
	}while(ch < '1' || ch > '3');
	cin.sync();
	cout << " Enter the Mobile no. : ";
	getline(cin, mob);
}
void person::print()
{
	cout << " Name   \t: " << name << endl;
	cout << " Age    \t: " << age << endl;
	cout << " Gender  \t: " << gen << endl;
	cout << " Mobile  \t: " << mob << endl;
}
// Derived Class 1 (Teacher) Function
void teacher::set()
{
	person::set();
	cin.sync();
	cout << " Enter the Teacher ID  : ";
	getline(cin,id);
	cout << " Enter the Department name : ";
	getline(cin, depart);
	cout << " Enter the Salary : ";
	cin >> salary;	
}
void teacher::print()
{
	person::print();
	cout << " Teacher ID\t: " << id << endl;
	cout << " Department\t: " << depart << endl; 
	cout << " Salary\t\t: " << salary << endl;
}
// Derived Class 2 (Student) Function
void student::set()
{
	person::set();	
	cout << " Enter the Student's roll number : ";
	cin >> roll;
	cin.sync();
	cout << " Enter the Course : ";
	getline(cin, course);
	do
	{
		cout << " Enter the Student's percent : ";
		cin >> per;
		if(per < 0 && per > 100)
			cout << "\n invalid input. \n";
	}while(per < 0 || per > 100);
}
void student::print()
{
	cout << " Roll No. \t: " << roll << endl;
	person::print();
	cout << " Course \t: " << course << endl; 
	cout << " Percentage \t: " << per << endl;
}
