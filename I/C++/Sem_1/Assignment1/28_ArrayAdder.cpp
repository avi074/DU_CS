/*****************************************************************************
comment about the program
*****************************************************************************/
#include <iostream>
//for extra headers
using namespace std;

void addArr(int len1 ,int len2 , int *num , int*num1)
{
	short int len3 = len1 + len2 ; 
	int num3[len3];
	bool big_1 = (len1 < len2);

	for(int i = 0, j = 0; i < len3; i++)
	{
		if(big_1)
		{
			if(i < len2)
				num3[i] = num1[i];
			else
			{
				num3[i] = num[j];
				j++;					
			}
		 }
		else
		{
			if(i < len1)			
				num3[i] = num[i];
			else
			{
				num3[i] = num1[j];
				j++;					
			}
		 }	
		cout << j<<"\t";
	}
	cout << "\n\n Your Concatenated Array : \n ";
	cout << "\n\t S.N. \t Elements \n";
	for(int i = 0; i < len3; i++)
		cout << "\t  " << i+1 << "\t  " << num3[i] << endl;	
}
int main()
{
	short int size1 , size2 ;
	int num[size1] , num1[size2];
	cout << "\n\t This Program concatenates the two arrays.";
	// prompt size of the array
	do
	{
		cout << "\n\n Enter the number of elements of first array :  ";
		cin >> size1;
		cout << "\n Enter the number of elements of second array :  ";
		cin >> size2;
		if(size1 <= 0 || size2 <= 0)
			cout << "\n Please enter a positive number except 0 or negative. \n";
	}while(size1 <= 0 || size2 <= 0);
	// entering elements
	cout << "\n\n Enter the elements : \n ";
	cout << "\n First Array \t S.N. \t Elements \n";
	for(int i = 0; i < size1; i++)
	{
		cout << "\t\t " << i+1 << "\t   " ;
		cin >> num[i];
	}
	cout << "\n Second Array \t S.N. \t Elements \n";
	for(int i = 0; i < size2; i++)
	{
		cout << "\t\t " << i+1 << "\t   " ;
		cin >> num1[i];
	}
	addArr(size1 ,size2, num, num1);
}
