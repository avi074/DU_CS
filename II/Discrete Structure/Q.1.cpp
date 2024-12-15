#include <iostream>
#include <cmath>
using namespace std;
int len = 0;

bool isMember(int A[], int a)
{
	bool find = false;
	for(int i = 0; i < len; i++)
	{
		if(A[i] == a){
			find = true;
			break;
		}
	}
	return find;
}

void PowerSet(int A[])
{
	int size = pow(2,len);
	int i,j,k;
	cout << "\n Power sets of A : ";
	
	for(i = 0; i < size; i++)
	{
		cout << "\t\t {";
		for(j = 0; j < len; j++)
		{
			if(i & (1 << j))
				cout << A[j] <<" ";
		}
		cout << "} \n";
	}
}

int main()
{
	int *A = 0;
	int a = 0;
	char ch ='\0';
	
	system("cls");
	cout << "\n Enter the total number of elements : ";
	cin >> len;
	A = new int[len];
	cout << "\n Enter the elements : ";
	for(int i = 0; i < len; i++) {
		cin >> A[i];
	}
	cout << "\n\n Options : \n\t 1. Find an element \n\t 2. Power Set";
	cout << "\n\n pick : ";
	cin >> ch;
	switch(ch) 
	{
	case '1':
		cout << "\n Value of element : ";
		cin >> a;
		if(isMember(A,a))
			cout << "\n " << a << " is an element of Set A.";
		else
			cout << "\n " << a << " is not an element of Set A.";
		break;
		
	case '2':
		PowerSet(A);
		break;
			
	default:
		cout << "\n INVALID INPUT !!!";
	}	
	cin.get();
	cin.ignore();
}

