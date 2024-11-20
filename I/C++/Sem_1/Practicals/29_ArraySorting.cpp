#include <iostream>

using namespace std;
#define swap(a,b) a = a + b, b = a - b, a = a - b;
void sort_(int *n, char o)
{
	int min, min_i;
	for(int i = 0; i < 10; i++)
	{
		min = n[i];
		min_i = i;
		for(int k = i; k < 10; k++)
		{
			if(min > n[k])
			{
				min = n[k];
				min_i = k;
			}
		}
		if(min_i != i)
			swap(n[i], n[min_i]);	
	}
	if(o == '1')
		return;
	else
	{
		for(int i = 0, j = 9; i < j; i++, j--)
			swap(n[i],n[j]);
	}
}

int main()
{
	char op;
	int num[10];
	cout << "\n\t\t Practical 29 \n\n Enter 10 elements....";
	cout << "\n\n\t S.N. \t Elements \n";
	for(int i = 0; i < 10; i++)
	{
		cout << "\t  " << i + 1 << "  \t  ";
		cin >> num[i]; 
	}
	cout << "\n ============================================== ";
	cout << "\n Choose an option \n\n\t 1. Ascending Order \n\t 2. Descending Order \n\n Enter your choice : ";
	cin >> op;
	cout << "\n ============================================== ";
	switch(op)
	{
		case '1':
			sort_(num,op);
			cout << "\n   Printing the array in ascending order \n";
			cout << "\n\t S.N. \t Elements \n";
			for(int i = 0; i < 10; i++)
				cout << "\n\t " << i+1 << "  \t  " << num[i];
			break;
			
		case '2':
			sort_(num, op);
			cout << "\n    Printing the array in descending order \n";
			cout << "\n\t S.N. \t Elements \n";
			for(int i = 0; i < 10; i++)
				cout << "\n\t " << i+1 << "  \t  " << num[i];
			break;
			
		default:
			cout << "\n\n invalid input \n";
	}
}
