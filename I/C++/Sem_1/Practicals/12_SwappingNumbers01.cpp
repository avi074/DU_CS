// This program swaps two numbers using pointers.
#include <iostream>
using namespace std;
void swap(float *a,float *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b; 
}
int main()
{
	float a,b;
	cout<<"\n\t\t      Practical 12 \n\t\t Swapping using pointers\n\n";
	cout<<" Enter first number : ";
	cin>>a;
	cout<<"\n Enter second number : ";
	cin>>b;
	swap(&a,&b);
	cout << "\n After Swapping... \n";
	cout << "\n\t first number  : " << a;
	cout << "\n\t second number : " << b << endl;
}
