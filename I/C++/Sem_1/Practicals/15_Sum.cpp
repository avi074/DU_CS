#include <iostream>

using namespace std;

int main()
{
	int num;
	float *ptr = NULL, sum = 0;
	cout << "\n\t\t Pratical 15 \n";
	cout << "\n This program calculates the sum of the entered numbers.\n\n";
	cout << " How many numbers do you want to calculate : ";
	cin >> num;
	//dynamic memory allocation
	ptr = new float[num];
	cout << "\n Enter the elements : \n\n";
	for(int i = 0; i < num; i++)
	{
		cout << "\t\t" << i+1 << "  :  ";
		cin >> ptr[i];
		sum += ptr[i];
	}
	cout << "\n The sum of the entered number is  : "<< sum << endl;
	delete[] ptr;
}
