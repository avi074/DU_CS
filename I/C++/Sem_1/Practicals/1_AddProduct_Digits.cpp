// This program calculate sum & product of digits of given integar.
// Date :- 06-01-2020
#include <iostream>
using namespace std;
int main(){
	int num,sum = 0, product = 1;
	cout << "\n\t\t Practical 1 \n";
	cout<<"\n This program calculate sum & product of digits of given integar.\n";
	cout<<"\n Enter the integar : ";
	cin>>num;
	if(num == 0)
		product = 0;
	for(int i = num ; i != 0 ; i /= 10)
	{
		sum += (i % 10);
		product *= (i % 10);		
	}
	cout << "\n Sum of the digits of " << num << " is  " << sum;
	cout << "\n\n Product of the digits of " << num << " is " << product << endl;
}
