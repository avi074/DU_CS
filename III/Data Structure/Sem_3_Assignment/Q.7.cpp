#include <iostream>
#include <iomanip>
#include "Sem_3/SinglyList.cpp"

using namespace std;

#define no_data(s) if(s.empty()){\
                    cout << "\n Error : No Data Avaliable !!!";\
                    return;}

#define error(b) if(!b){\
                    cout << "\n Error : No match found !!!";\
                    return;}

bool once = 0;
const char getGrade[] = "ABCDF";

class student
{
private:
    string f_name, l_name, c_code;
    char grade;

public:
    student(){}
    student(const string& s,const string& s1,const string& s2, const char& c){
        f_name = s;
        l_name = s1;
        c_code = s2;
        grade = c;
    }

    bool chk_code(const string& c) const{
        return c == this->c_code;
    }

    bool chk_l_name(const string& l) const{
        return l == this->l_name;
    }

    short grade_no() const{
        for(short i = 0; i < 5; i++)
            if(this->grade == getGrade[i])
                return i;
    }
    
    friend istream& operator>>(istream &in, student &s);

    friend ostream& operator<<(ostream &out, const student &s);

    bool operator==(const student& s){
        return this->f_name == s.f_name && this->l_name == s.l_name && this->c_code == s.c_code && this->grade == s.grade;
    }

    ~student(){}
};

void print(SinglyList<student>& l)
{
    no_data(l);
    once = 1;
    for(auto i:l)
        cout << i;
}

void search(SinglyList<student>& f){
    no_data(f);
    string str;
    bool found = 0;

    cout << "\n\n Enter the last name of student : ";
    cin >> str;
    once = 1;
    for(student i:f)
        if(i.chk_l_name(str)){
            cout << i;
            found = 1;
        }
    error(found);
}

void del(SinglyList<student>& l, student& asp){
    no_data(l);
    error(l.erase(asp));
    cout << "\n Data has been deleted successfully !!!";
}

void avg_class(SinglyList<student>& l){
    no_data(l);
    string str;
    ushort sum = 0, n = 0;
    bool found = 0;

    cout << "\n\n Enter the course code of a class : ";
    cin >> str;

    for(student i:l){
        if(i.chk_code(str)){
            n++;
            sum += i.grade_no();
            found = 1;
        }
    }
    error(found);
    cout << "\n Class avarage score of course " + str + " : " << getGrade[sum/n] << endl;
}

int main(){
    char op;
    student s;

    SinglyList<student> lst;
    
    do{
        system("clear");
        cout << "\n<------------------------------------- Menu ---------------------------------------->\n";
        cout << "\n\t 1. Insert a new record \n\t 2. Delete a record" 
             << "\n\t 3. Search the database (by last name) \n\t 4. Print records in the database"
             << "\n\t 5. Find the class average for a course \n\t 9. Quit \n";
        cout << "\n Enter the option : ";
        cin >> op;
        cout << "\n<------------------------------------------------------------------------------------>\n";

        switch(op){
            case '1':
                cout << "\n<------------------------------ Insertion of a Record ------------------------------->\n";
                cin >> s;
                lst.push(s);
                break;
            
            case '2':
                cout << "\n<------------------------------- Deletion of a Record ------------------------------->\n";
                cin >> s;
                del(lst,s);
                break;

            case '3':
                cout << "\n<------------------------------ Searching of a Record ------------------------------->\n";
                search(lst);
                break;
            
            case '4':
                cout << "\n<------------------------------ Printing all Records -------------------------------->\n";
                print(lst);
                break;
            
            case '5':
                cout << "\n<------------------------ Finding average score of a course ------------------------->\n";
                avg_class(lst);
                break;

            default:
                if(op != '9')
                    cout << "\n Wrong Input, Please re-enter !!!";
        }
        cin.get();
        cin.ignore();
    }while(op != '9');
}

// For the input of the student's details
istream &operator>>(istream &in, student &s)
{
    short c;
    cout << "\n**************************** Enter Student's Details *******************************\n";
    cout << "\tNote:\n"
         << "\t\t1. Course code must not be more than 6 numbers or letters.\n"
         << "\t\t2. For Grading : (1 for A, 2 for B, 3 for C, 4 for D, 5 for F)\n\n";
    in.ignore();
    cout << "\n First name \t: ";
    getline(in, s.f_name);

    cout << " Last name  \t: ";
    getline(in, s.l_name);

    cout << " Course Code\t: ";
    getline(in, s.c_code);
    
    do
    {
        cout << " Grade \t\t: ";
        in >> c;
        if (c < 1 || c > 5)
        {
            cout << "\n Invalid Entry !!! Please Re-enter !!!\n";
            c = -1;
        }
        else
            s.grade = getGrade[c - 1];
    } while (c == -1);

    cout << "\n*************************************************************************************\n";
    return in;
}

// For the output of the student's details
ostream &operator<<(ostream &out, const student &s)
{
    if(once){
        out << '\n' << left << setw(25) << " First Name " << setw(25) << " Last Name " << setw(17) << "Course Code" << setw(10) << "Grade\n";
        once = 0;
    }

    out << "\n  " << left << setw(25) << s.f_name << setw(25) << s.l_name << setw(17) << s.c_code << setw(10) << s.grade;
    return out;
}