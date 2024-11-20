#include <iostream>
#include <cmath>

using namespace std;

class triangle
{	
	float l1, l2, l3;
	
	public:
	void set(float, float, float);
	void check_();
	void print();
	void area(float);
	void area(float,float);
	void area(float,float,float);
	triangle& operator=(triangle);
	bool operator==(triangle);
	~triangle(){};
};

void triangle::set(float a, float b, float c)
{ // initialising the values in ascending order
	l1 = (a < b && a < c ? a : (b < c ? b : c));
	l3 = (a > b ? (a > c ? a : c) : (b > c ? b : c));
	l2 = a + b + c - l1 - l3;
}
void triangle::print()
{
	cout << "\n\t The parameters of the Triangle :  " << l1 <<"\t" << l2 << "\t" << l3 << endl;
}
void triangle::check_()
{	
	if(l3 >= l1 + l2)
		cout << "\n\n\t This is wrong parameters for a triangle.\n";
	else if(l1 == l2 && l2 == l3)
		area(l1);
	else if(l3*l3 == (l1*l1 + l2*l2))
		area(l1,l2);
	else
		area(l1, l2, l3);
}
void triangle::area(float a)
{
	float area = (1.732 * a *a) / 4;
	cout << "\n\n\t The area of triangle  :  " << area << endl;
}
void triangle::area(float a, float b)
{
	float area = 0.5 * a * b;
	cout << "\n\n\t The area of triangle  :  " << area << endl;
}
void triangle::area(float a, float b, float c)
{
	float area, s;
	
	s = (a+b+c) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));		
	cout << "\n\n\t The area of triangle  :  " << area << endl;
}
triangle& triangle::operator=(triangle r)
{
	l1 = r.l1;
	l2 = r.l2;
	l3 = r.l3;
	return (*this);
}
bool triangle::operator==(triangle r)
{
	bool equal;
	equal = (l1 == r.l1 && l2 == r.l2 && l3 == r.l3);
	return equal;
}
void set_(float &a, float &b, float &c)
{
	bool non_valid = false;
	do
	{
		cout << "\n\n Enter the parameters of the triangle.....";
		cout << "\n\n\t\t Side1 length : ";
		cin >> a;
		cout << "\t\t Side2 length : ";
		cin >> b;
		cout << "\t\t Side3 length : ";
		cin >> c;
		
		if(a <= 0 || b <= 0 || c <= 0)
		{
			cout << "\n\n The length of the triangle can't be negative nor 0." << endl;
			non_valid = true;
		}
		else
			non_valid = false;
	}while(non_valid);
}
int main()
{
	float s1, s2, s3;
	char op = 0;
	triangle t1, t2, T3;
	
	cout << "\n\t\t\t Practical 23 \n";
	cout << "\n This program operates on a Triangle. ";
	set_(s1,s2,s3);
	t1.set(s1,s2,s3);

	while(op != '4')
	{
		cout << "\n\n Choose :- \n\n\t 1. Calculate Area \n\t 2. Overload assignment operator \n\t 3. Overload equality operator";
		cout << "\n\t 4. Quit \n\n Enter your choice :-  ";
		cin >> op;
		switch(op)
		{
			case '1':
				t1.check_();
				break;
				
			case '2':
				t2 = t1;
				cout << "\n First Triangle \n";
				t1.print();
				cout << "\n Second Triangle \n";
				t2.print();
				break;
				
			case '3':
				set_(s1,s2,s3); // set new parameters	
				T3.set(s1,s2,s3);		
				if(T3 == t1)
					cout << "\n\n The parameters of two triangles are same.\n";
				else
					cout << "\n\n The parameters of two triangles are not same.\n";	
				break;		
				
			default:
				if(op != '4')
					cout << "\n\n Invalid input.\n";
		}
	}
}
