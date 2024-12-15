#include <iostream>
#include "STL/linked_list.hpp"

using namespace std;
using namespace stl;

void input_p(const int& d, singlyList<float>& s)
{
	cout << "\n Enter the coefficients (descending order) : ";
	for (int i = 0; i <= d; i++)
		cin >> s;
}

void print(const int& d, const singlyList<float>& s)
{
	auto v = s.begin();
	for(int i = d; i >= 0; i--, v++)
	{
		if(i < d && *v >= 0)
			cout << "+ ";
		cout << *v ;
		if(i)
		{
			cout << 'x';
			if(i != 1)
			cout << '^' << i;
			cout << ' ';
		}
	}
	cout << endl;
}

int main()
{
	int d = 4;
	singlyList<float> p1, p2, p3;

	cout << "\n\t Practical 10 \n";

	cout << "\n Enter the highest degree of polynomials : ";
	cin >> d;
	
	cout << "\n First Polynomial's Parameter : ";
	input_p(d, p1);
	cout << "\n Second Polynomial's Parameter : ";
	input_p(d, p2);
	
	cout << "\n First Polynomial : ";
	print(d, p1);
	cout << "\n Second Polynomial : ";
	print(d, p2);
	
	singlyList<float>::iterator i1 = p1.begin(), i2 = p2.begin();
	while(i1 != p1.end()){
		p3.push_back((*i1) + (*i2));
	i1++;++i2;	
	}
	cout << "\n After addition of these polymonials : \n Final Polynomial  : ";
	print(d, p3);
}
