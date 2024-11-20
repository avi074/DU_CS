#include <iostream>

using namespace std;

class Box
{
	float l, b, h;
	
	public:
		void set();
		void calcArea();
		void calcVol();
		void check_();
		void print();
		Box& operator=(Box);
		Box operator++();
		Box operator++(int);
		Box operator--();
		Box operator--(int);
		friend bool operator==(Box, Box);
		~Box(){};
};
void Box::set()
{
	bool non_valid = false;
	do
	{
		cout << "\n\n Enter the parameters of the box...";
		cout << "\n\n\t\t\t  Length  : ";
		cin >> l;
		cout << "\t\t\t  Breath  : ";
		cin >> b;
		cout << "\t\t\t  Height  : ";
		cin >> h;
		
		if(l <= 0 || b <=0 || h <=0)
		{
			cout << "\n You entered wrong parameters. Please correct it.";
			non_valid = true;
		}
		else
			non_valid = 0;
	}while(non_valid);
}
void Box::calcArea()
{
	float area, area1;	
	area = 2 * (l*b + b*h + h*l);
	cout << "\n The Surface Area of the box is " << area << endl;
	area1 = 2 * h * (l+b);
	cout << "\n The Curved Surface Area of the box is " << area1 << endl;	
}
void Box::calcVol()
{
	float vol;
	vol = l * b * h;
	cout << "\n\n The Volume of the box is " << vol << endl;
}
void Box::check_()
{
	bool chk;	
	chk = (l == b && b == h);
	
	if(chk)
		cout << "\n\n\t This box is cube.\n";
	else
		cout << "\n\n\t This box is cuboid.\n";
}
void Box::print()
{
	cout << "   Length : " << l << "\t Breadth : " << b << "\t Height : " << h << endl;
}
Box& Box::operator=(Box r)
{
	l = r.l;
	b = r.b;
	h = r.h;
	return (*this);
}
bool operator==(Box b1, Box b2)
{
	bool equal;
	equal = (b1.l == b2.l && b1.b == b2.b && b1.h == b2.h);
	return equal;
}
Box Box::operator++()
{
	l++;
	b++;
	h++;
	return(*this);
}
Box Box::operator++(int)
{
	Box tmp;
	tmp.l = l++;
	tmp.b = b++;
	tmp.h = h++;
	return(tmp);
}
Box Box::operator--()
{
	l--;
	b--;
	h--;
	return(*this);
}
Box Box::operator--(int)
{
	Box tmp;
	tmp.l = l--;
	tmp.b = b--;
	tmp.h = h--;
	return(tmp);
}
int main()
{
	char ch;
	Box b;
	
	cout << "\t\t\t Practical 24  ";
	b.set();
	
	do
	{
		cout << "\n ===============================================================";
		cout << "\n Choose an option......";
		cout << "\n\n\t 1. Calculate Area \n\t 2. Calculate Volume \n\t 3. Overload ++ prefix operator"
			 << "\n\t 4. Overload ++ postfix operator \n\t 5. Overload -- prefix operator "
			 << "\n\t 6. Overload -- postfix operator \n\t 7. Overload Assignment Operator "
			 << "\n\t 8. Overload Equality Operator \n\t 9. Check the box is cube or cuboid ";
		cout << "\n\n Enter your choice (0 for exit) : ";
		cin >> ch;
		cout << "\n ===============================================================";
		switch(ch)
		{
			case '1':
				cout << "\n ....................Calculating Area.................\n\n";
				b.calcArea();
				break;
				
			case '2':
				cout << "\n ....................Calculating Volume.................";
				b.calcVol();
				break;
				
			case '3':
				{
					Box b1;
					cout << "\n ...........Overloading ++ prefix operator..........."; 
					b1 = ++b;
					cout << "\n\n Box 1 : ";
					b.print();
					cout << "\n Box 2 : ";
					b1.print();
				}
				break;
				
			case '4':
				{
					Box b1;
					cout << "\n ...........Overloading ++ postfix operator.........."; 
					b1 = b++;
					cout << "\n\n Box 1 : ";
					b.print();
					cout << "\n Box 2 : ";
					b1.print();
				}
				break;
			
			case '5':
				{
					Box b1;
					cout << "\n ...........Overloading -- prefix operator..........."; 
					b1 = --b;
					cout << "\n\n Box 1 : ";
					b.print();
					cout << "\n Box 2 : ";
					b1.print();
				}
				break;
			
			case '6':
				{
					Box b1;
					cout << "\n ...........Overloading -- postfix operator.........."; 
					b1 = b--;
					cout << "\n\n Box 1 : ";
					b.print();
					cout << "\n Box 2 : ";
					b1.print();
				}
				break;
			
			case '7':
				{
					Box b1;
					cout << "\n ...........Overloading Assignment operator.........."; 
					b1 = b;
					cout << "\n\n Box 1 : ";
					b.print();
					cout << "\n Box 2 : ";
					b1.print();
				}
				break;
			
			case '8':
				{
					Box b1;
					cout << "\n ...........Overloading Equality operator.........."; 
					b1.set();
					
					if(b1 == b)
						cout << "\n\n Both of the boxes are same. \n";
					else
						cout << "\n\n Both of the boxes are not same.\n";
				}
				break;
				
			case '9':
				cout << "\n .....................Checking.....................";
				b.check_();
				break;
				
			default:
				if(ch != '0')
					cout << "\n\n Invalid input.\n";
		}
	}while(ch != '0');
}
