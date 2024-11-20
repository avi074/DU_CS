/*****************************************************************************
comment about the program
*****************************************************************************/
#include <iostream>
//for extra headers
using namespace std;

void merge(int l, int l1, int *a, int *a1)
{
	int l2 = l + l1, a2[50];
	bool a_big = true, a1_big = true;
	
	for(int i = 0, j= 0, i1 = 0; j < l2; j++)
	{
		if(i == l)
			a_big = false;
		else if(i1 == l1)
			a1_big = false;
		if(!a_big)
		{
			a2[j] = a1[i1];
			++i1;
		}
		else if(!a1_big)
		{
			a2[j] = a[i];
			++i;
		}
		else
		{
			if(a[i] > a1[i1])
			{
				a2[j] = a1[i1];
				i1++;
			}
			else if(a[i] < a1[i1])
			{
				a2[j] = a[i];
				++i;
			}
			else 
			{
				a2[j] = a[i];
				++i;
				i1++;
				--l2;
			}	
		}
			
	}			
	cout << "\n\n\t S.N. \t Elements \n";
	for(int i= 0; i < l2; i++)
		cout << "\t  " << i+1 << "\t  " << a2[i] << endl;
}

int main()
{
	short int len, len1;
	int arr[15], arr1[15];
	
	cout << "\n\t This program merges the two array into an array.";
	do
	{
		cout << "\n\n How many elements do you want to enter in...\n\n\t\t First array : ";
		cin >> len;
		cout << "\n\t\t Second array : ";
		cin >> len1;
		
		if(len <= 0 || len1 <= 0)
			cout << "\n please enter an positive number not 0 or negative." << endl;
	}while(len <= 0 || len1 <= 0);
	
	cout << "\n Enter the elements of First array : ";
	cout << "\n\n\t S.N. \t Elements \n";
	for(int i = 0; i < len;i++)
	{
		cout << "\t  " << i+1 << "\t   ";
		cin >> arr[i];
	}
	
	cout << "\n Enter the elements of Second array : ";
	cout << "\n\n\t S.N. \t Elements \n";
	for(int i = 0; i < len1;i++)
	{
		cout << "\t  " << i+1 << "\t   ";
		cin >> arr1[i];
	}
	cout << "\n\n After Merging these two arrays... \n\n Your New Array : ";
	merge(len, len1, arr, arr1);
}
