#include <iostream>
using namespace std;
void func(int *a, int*b)
{
	*a /= 4;
	*b *= 2;
}
int main()
{
	int a1 , a2;
	cout<<"\n\t\t Practical 13 ";
	cout<<"\n\n Enter first number : ";
	cin>>a1;
	cout<<"\n Enter second number : ";
	cin>>a2;
	func(&a1, &a2);
	cout << "\n\n Your numbers after function : " << a1 << " & " << a2 << endl;
}
