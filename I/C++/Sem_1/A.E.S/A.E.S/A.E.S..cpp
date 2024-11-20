#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

class aspirant
{ //attributes
	float apply_no;
	char name[40], f_name[40], m_name[40];
	char gender[12], pwd[16], dob[12];
	char stream_12[10], col_apply[50], course[50];
	float percent_10, percent_12;
	bool diff;
public: //member function
	void input_data();
	void chk_percent();
	void apply_();
	void final_();
	void write_data();
	void search_data(string);
	void search_data(float);
	void chk_details();
	void edit_data();
	void display_data();
	void del_data();
	~aspirant(){};
};
aspirant asp; // Global aspirant object.
fstream rec;  // Global File object.
bool edit = false, no_seats = false;
short col_no, cor_no;

void search_parameter() 	// searching parameters
{
	char pick;
	string s1;
	float s;

	cout << "\n\n ...................Search Your application................\n";
	do
	{
		cout << "\n Your options : \n\n\t 1. By Name \n\t 2. By Application No. \n\t 3. Back to main menu";
		cout << "\n\n\t Your choice : ";
		cin >> pick;
		if (pick < '1' || pick > '3')
			cerr << "\n\t Please choose a right option. \n";
	} while (pick < '1' || pick > '3');
	cin.ignore();
	switch (pick)
	{
	case '1':
		cout << "\n Enter your name : ";
		getline(cin, s1);
		break;
	case '2':
		cout << "\n Enter your application no. : ";
		cin >> s;
		break;
	case '3':
		break;
	}

	if (pick == '1')
		asp.search_data(s1);
	else if (pick == '2')
		asp.search_data(s);
}
void about()
{
	ifstream about;
	string str;
	about.open("About.txt");
	if (about.fail())
	{
		cerr << "\n\t Error occurs in opening file.";
		return;
	}
	cout << "\n\n";
	while (!about.eof())
	{
		getline(about, str);
		cout << str << endl;
	}
	about.close();
}
void seats() 	// syncing seats
{
	short seat;
	fstream file;
	file.open("seats.dat", ios::in | ios::out | ios::binary);

	if (!file)
		cerr << "\n\n ERROR!!! \n";
	else
	{
		//reading no. of seats
		file.seekg(15*cor_no + col_no * 3,ios::beg);
		file >> seat;
		if(!seat)
		{
			cout << "\n\n Sorry, There are no seats avaliable for this course in this college.\n";
			no_seats = true;
		}
		else
		{
			// seat reduce by one
			seat--;
			//writing avaliable seats no.
			file.seekp(15*cor_no + col_no * 3,ios::beg);
			file << seat;
		}
	}
	file.close();
}
int main()
{
	char choice = '\0';
	while (choice != '6')
	{
		system("cls"); // clear the screen 
		cout << "\n======================================================";
		cout << "\n\t\t\t \" Welcome to A.E.S. \"";
		cout << "\n\n Choose an option...."
			 << "\n\n\t 1. Apply for new admission \n\t 2. Display your application \n\t 3. Check eligibility"
			 << " \n\t 4. Search your application \n\t 5. About Colleges & University \n\t 6. Quit ";
		cout << "\n\n Enter your choice : ";
		cin >> choice;
		cout << "\n======================================================";
		switch (choice)
		{
		case '1':
			asp.chk_percent();
			break;

		case '2':
			asp.chk_details();
			break;

		case '3':
			asp.chk_percent();
			break;

		case '4':
			search_parameter();
			break;

		case '5':
			about();
			break;

		default:
			if(choice != '6')
				cout << "\n Invalid input!!!";
		}
		
		if(choice != '6')
		{
			cout << endl << endl << endl;
			system("pause"); // break untill the next input
		}
	}
	cout << "\n\n====================== Thanks for visiting ==========================" << endl;
	Sleep(2000);//for waiting 
}
void aspirant::input_data() // Input data
{
	char op;
	cin.ignore();

	cout << "\n\n ..........................Personal Details............................ \n";
	cout << "\n Enter your name  :  ";
	cin.getline(name, 40);
	cout << "\n Enter your father's name  :  ";
	cin.getline(f_name, 40);
	cout << "\n Enter your mother's name  :   ";
	cin.getline(m_name, 40);
	cout << "\n Enter your D.O.B. (eg : 02-02-1995) :  ";
	cin.getline(dob, 12);
	do
	{
		cout << "\n Enter your gender (1 for Male, 2 for Female, 3 for Transgender) :  ";
		cin >> op;
		if (diff && op == '1')
		{
			op = 0;
			cout << "\n\n You have chosen the Girls College. So you can't be the male student.\n";
		}
		if (op < '1' && op > '3')
			cerr << "\n Please choose a right option. \n";
	} while (op < '1' && op > '3');

	switch (op)
	{
	case '1':
		strcpy(gender, "Male");
		break;
	case '2':
		strcpy(gender, "Female");
		break;
	case '3':
		strcpy(gender, "Transgender");
		break;
	}
	cin.ignore();
	cout << "\n Enter the password (Max 16 characters):  ";
	cin.getline(pwd, 16);
	// finalising the details
	final_();
}
void aspirant::chk_percent() // checking eligibility
{
	char st;
	short int obt[3], total[3];
	float percent[3], sum = 0;

	cout << "\n\n ........................Academic Qualification....................\n";

	do //
	{
		cout << "\n Enter your 10th percentage  :  ";
		cin >> percent_10;

		if (percent_10 < 40 || percent_10 > 100)
			cerr << "\n Please enter right percentage.\n";
	} while (percent_10 < 40 || percent_10 > 100);

	do //
	{
		cout << "\n Enter your 12th stream (1 for Arts, 2 for Commerce, 3 for Science)  :  ";
		cin >> st;

		if (st == '1')
			strcpy(stream_12, "Arts");
		else if (st == '2')
			strcpy(stream_12, "Commerce");
		else if (st == '3')
			strcpy(stream_12, "Science");
		else
		{
			st = '0';
			cerr << "\n Please choose a right option.";
		}
	} while (st == '0');

	cout << "\n Enter your Core/Optional Subject marks......\n";
	for (int i = 0; i < 3;)
	{
		cout << "\n Subject_" << i + 1 << " obtained marks (Theory + Practical)  : ";
		cin >> obt[i];
		cout << "\n Subject_" << i + 1 << " total marks  : ";
		cin >> total[i];
		if (obt[i] > total[i])
		{
			cerr << "\n Total marks should be greater than obtained marks. \n";
			continue;
		}
		percent[i] = obt[i] * 100.0 / total[i];
		sum += percent[i];
		i++;
	}
	percent_12 = sum / 3; //12th percentage on behalf of core subject marks
	
	if (percent_12 <= 75)
		cerr << "\n\n Your percantage should be greater than 75 % for the admission in this University. \n";
	else
	{
		cout << "\n\n Your 12th percentage : " << percent_12 << endl;
		if(!edit)
			apply_(); // proceed for apply	
	}
}
void aspirant::apply_() // checking seats in required colleges
{
	bool present = false;
	short ch, percent[5][5] = {
								  {85, 90, 93, 89, 84},
								  {86, 91, 94, 88, 85},
								  {80, 89, 85, 84, 86},
								  {78, 86, 85, 81, 80},
								  {80, 85, 88, 84, 82}
				 			 };

	string corse[5] = {
						"1. B.A. (Hons) English",
						"2. B.A. (Hons) Hindi",
						"3. B.Com (Hons)",
						"4. B.Sc (Hons) Computer Science",
						"5. B.Sc (Hons) Maths"
						},
		   col[5] = {
					   "1. Gargi College (Only for Girls)", 
					   "2. Hansraj College", 
					   "3. Hindu College", 
					   "4. Miranda College (Only for Girls)", 
					   "5. Ramanujan College"
		   			};

	cout << " \n Choose your Course : \n\n";
	for (int i = 0; i < 5; i++)
		cout << "\t" << corse[i] << endl;
	do
	{
		cout << "\n Enter your choice : ";
		cin >> ch;

		if (ch > 6 && ch < 1)
			cerr << "\n Please enter righ choice.\n";
		else
		{
			strcpy(course, corse[ch-1].c_str()); //strcpy(char*, const char*)
			cor_no = ch - 1;
		}			
	} while (ch > 6 && ch < 1);
	cout << " \n\n You can apply  : \n\n";
	for (int i = 0; i < 5; i++)
		if (percent[ch-1][i] <= percent_12)
		{
			cout << "\t" << col[i] << endl;
			present = true;
		}

	if (present)
	{
		do
		{
			cout << "\n Enter your choice : ";
			cin >> ch;

			if (ch > 6 && ch < 1)
				cerr << "\n Please enter righ choice.\n";
			else
			{
				strcpy(col_apply, col[ch - 1].c_str());
				col_no = ch - 1;	
			}
		} while (ch > 6 && ch < 1);
	}
	else
		cerr << "\n Your percentage is not enough for the course.\n";
	
	seats(); // no. of seats
	if(no_seats)
	{
		no_seats = false;
		return;
	}
	if (present)
	{
		(ch == 1 || ch == 4) ? diff = true : diff = false;
		cout << "\n\n Do you want to apply for " << col[ch - 1] << " ? (1 for yes / otherwise no)  : ";
		cin >> ch;

		if (ch == 1)
			input_data();
	}
}
void aspirant::final_() // finalising application
{
	time_t t = time(NULL);
	tm* t_ptr = localtime(&t);
	srand(time(NULL));
	short static num = 0;
	
	if(col_no == 0 || col_no == 3)
		num += 200;
	else if(col_no == 1)
		num += 500;
	else
		num += 700;
	
	apply_no = (t_ptr->tm_year + 1900) * 1000000;
	apply_no += col_no * 100000 + cor_no * 10000;
	apply_no += rand() % num;
	cout.precision(0);
	cout << fixed <<  "\n\n Your application number is  : " << apply_no << endl;
	//writing into a file
	write_data();
	cout << "\n Please read it carefully !!! \n Note :- If you apply another college in the University."
		 << " Your past application has been automatically rejected.\n";
	
	num += 100;
	delete[] t_ptr;	
}
void aspirant::write_data() // writing data in file
{
	rec.open("record.dat", ios::out | ios::app | ios::binary); // open in append mode
	if (!rec)
		cerr << "\n\n Error in opening file!!! \n";
	else
	{
		rec.write((char *)this, sizeof(*this));
		rec << endl;
		cout << "\n Your application has been submitted successfully.\n";
	}
	rec.close();
}
void aspirant::search_data(string s) // searching data by name
{
	aspirant *tmp = new aspirant;
	rec.open("record.dat", ios::in | ios::binary);
	bool not_find = true;
	short len = s.length() - 1, no = 0;
	string Pas;

	cout << "\n  S.N. \t Application no. \tApplicant's name \tFather's name \t\tD.O.B. \n" ;
	if(rec.is_open())
	{
		while (rec.read((char *)tmp, sizeof(*tmp)))
		{
			if (!(strncmp(tmp->name, s.c_str(), len)))
			{
				not_find = false;
				cout.precision(0);
				no++;
				cout << fixed << "\n   " << no << " \t " << tmp->apply_no << setw(25) << tmp->name << setw(25) << tmp->f_name << setw(20) << tmp->dob;
			}
		}		
	}
	if(not_find)
		cerr << "\n\n There is no data regarding it. \n";
	rec.close();
	delete tmp;
}
void aspirant::search_data(float a) // searching data by application no.
{
	aspirant *tmp = new aspirant;
	rec.open("record.dat", ios::in | ios::binary);
	bool find = false;
	short int no = 0;
	string Pas;

	cout << "\n  S.N. \t Application no. \tApplicant's name \tFather's name \t\tD.O.B. \n";
	if(rec.is_open())
	{
		while (rec.read((char *)tmp, sizeof(*tmp)))
		{
			find = (a == tmp->apply_no);
			if (find)
			{
				cout.precision(0);
				no++;
				cout << fixed << "\n    " << no << " \t " << tmp->apply_no << setw(25) << tmp->name << setw(25) << tmp->f_name << setw(20) << tmp->dob;
				break;
			}	
		}
	}
	if (!find)
		cerr << "\n\n There is no data regarding it. \n";
	rec.close();
	delete tmp;
}
void aspirant::chk_details() // checking details for an application
{
	float s;
	string pass;
	bool right = false;
	aspirant *tmp = new aspirant;

	cout << "\n\n Enter your application no. : ";
	cin >> s;
	rec.open("record.dat", ios::in | ios::binary);
	if (!rec)
	{
		cerr << "\n Unable to open!!!";
		delete tmp;
	}
	else
	{
		while (!rec.eof())
		{
			rec.read((char *)tmp, sizeof(*tmp));
			if (tmp->apply_no == s)
			{
				right = true;
				asp = *tmp;
				break;
			}
		}
		delete tmp;
		if (!right)
		{
			cout << "\n\n You entered a wrong application number. \n";
			rec.close();
			return;
		}
		else
		{
			cin.ignore(); // cin.sync()
			cout << "\n Enter the password : ";
			getline(cin, pass);
			right = strcmp(pwd, pass.c_str());
			rec.close();
			if (right)
				cerr << "\n\n You entered wrong password. \n";
			else
				display_data();
		}
	}
}
void aspirant::display_data() // displaying the application
{
	char opt;
	bool invalid = false;

	cout << "\n\n .......................Your Application...................... \n";
	cout << fixed << setprecision(0);
	cout << "\n\t Application No.  \t: " << apply_no;
	cout << "\n\t Applicant's name \t: " << name;
	cout << "\n\t Father's name   \t: " << f_name;
	cout << "\n\t Mother's name    \t: " << m_name;
	cout << "\n\t Date of Birth    \t: " << dob;
	cout << "\n\t Gender/ Sex    \t: " << gender;
	cout.precision(2);
	cout << "\n\t 10th Percantage  \t: " << percent_10;
	cout << "\n\t 12th Stream      \t: " << stream_12;
	cout << "\n\t 12th Percantage  \t: " << percent_12;
	cout << "\n\t Applied Course \t: " << course;
	cout << "\n\t Applied College \t: " << col_apply << endl;

	do
	{
		cout << "\n\t 1. Edit the details \t 2. Delete your application \t 3. Back to Main";
		cout << "\n\n\t Enter your choice  :  ";
		cin >> opt;
		if (opt < '1' || opt > '3')
		{
			invalid = true;
			cout << "\n\n Please enter a proper choice. \n";
		}
		else
			invalid = false;
	} while (invalid);

	if (opt == '1')
		asp.edit_data();
	else if (opt == '2')
		asp.del_data();
}
void aspirant::edit_data() // edit the attributes
{
	char ch, op;
	cout << "\n\n ........................Edit Your Details....................\n";
	do
	{
		cout << "\n What you want to edit :  \n\t 1. Your name \n\t 2. Your Father's name \n\t 3. Your Mother's name "
			 << "\n\t 4. Gender \n\t 5. Date of Birth \n\t 6. Password \n\t 7. Academic Qualifications "
			 << "\n\t 8. Back to Main ";
		cout << "\n\n Enter your choice  :  ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\n Enter your name  :  ";
			cin.getline(name, 40);
			break;

		case 2:
			cout << "\n Enter your father's name  :  ";
			cin.getline(f_name, 40);
			break;

		case 3:
			cout << "\n Enter your mother's name  :   ";
			cin.getline(m_name, 40);
			break;

		case 4:
			do
			{
				cout << "\n Enter your gender (1 for Male, 2 for Female, 3 for Transgender) :  ";
				cin >> op;
				if (op == '1')
					strcpy(gender, "Male");
				else if (op == '2')
					strcpy(gender, "Female");
				else
					strcpy(gender, "Transgender");

				if (op < '1' && op > '3')
					cerr << "\n Please choose a right option. \n";
				if (diff && op == '1')
				{
					op = 0;
					cout << "\n\n You have chosen the Girls College. So you can't the male student.\n";
				}
			} while (op < '1' && op > '3');
			break;

		case 5:
			cout << "\n Enter your D.O.B. (eg : 02-02-1995) :   ";
			cin.getline(dob, 12);
			break;

		case 6:
			cout << "\n Enter your new password  : ";
			cin.getline(pwd, 16);
			break;

		case 7:
			edit = true;
			asp.chk_percent();
			edit = false;
			break;

		case 8:
			break;

		default:
			cout << "\n Invalid input \n";
		}
	} while (ch != '8');
}
void aspirant::del_data() // delete the particular data
{
	float st = apply_no;
	ofstream f;
	bool rmv = false;

	cout << "\n\n ...........................Delete Your Application................................";
	rec.open("record.dat", ios::in | ios::binary);
	f.open("new.dat", ios::out | ios::binary);

	if (!rec)
	{
		cerr << "\n\n Error occurred in existing file. \n";
		remove("new.dat");
		return;
	}
	else if (!f)
		cerr << "\n\n Error occurred in opening file.\n";
	else
		while (!rec.eof())
		{
			rec.read((char *)this, sizeof(*this));
			if (st != apply_no)
			{
				rmv = true;
				f.write((char *)this, sizeof(*this));
				f << endl;
			}
		}
	rec.close();
	f.close();
	if(rmv)
	{
		remove("record.dat");
		rename("new.dat", "record.dat");
		cout << "\n\n Your applicaion has been deleted successfully.\n";
	}
}
