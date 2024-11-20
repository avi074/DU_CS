// This program generates the star triangle in lines.
#include <iostream>
using namespace std;
int main()
{
	short int n;
	cout << "\n\t\t Practical 9 " << endl;
	cout << "\n This program generates the star triangle. \n";
	
	cout << "\n\n How many lines of star triangle do you want : ";
	cin >> n;
	cout << endl << endl;
	
	if(n < 0)
		cout << "\n Please enter a positive number. \n";
	
	for(int i = 1; i<=n ; i++)
	{
		cout << "\t *";
		for(int j = 2 ; j <= i ;j++)
			cout << "**";		
		cout<<endl;
	}
}
