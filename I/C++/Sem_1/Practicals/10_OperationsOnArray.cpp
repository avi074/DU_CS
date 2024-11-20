/*****************************************************************************
 File name :- 10_OperationsOnArray.cpp
 Date :- 14-01-2021 
 
 Description :- 
 				This program performs some operations on Array.
 				Note :- All booleans are only for error or exception checking.
*****************************************************************************/
#include <iostream>
using namespace std;

int enterArr(int array[]) // for entering elements
{
	int ele;
	cout << "\n\n How many elements do you want to enter : ";
	cin >> ele;
	
	if (ele <= 0)
	{
		cout << "\n\n Enter a positive number.\n";
		return enterArr(array);
	}	
	cout << "\n Enter the elements  : \n\n ";
	cout << "\t S.N. :\t Elements \n\n" ;
	for (int i = 0; i < ele; i++)
	{
		cout << "\t  " << i + 1 << "  :\t  ";
		cin >> array[i];
	}
	return ele;
}

void evenEle(int ele , int array[]) // for checking even numbers
{
	bool even = false;
	for (int i = 0; i < ele; i++)
	{
		if ((array[i] % 2) == 0)
		{
			cout << "\t n[" << i + 1 << "]  :  " << array[i];
			even = true;
		}
	}
	if (even == 0)
		cout << "\n There is no even-valued elements. \n";	
}

void oddEle(int ele , int array[]) // for checking odd numbers
{
	bool odd = false;
	for (int i = 0; i < ele; i++)
	{
		if ((array[i] % 2) == 1)
		{
			cout << "\t n[" << i + 1 << "]  :  " << array[i];
			odd = true;
		}
	}
	if (odd == 0)
		cout << "\n There is no odd-valued elements. \n";	
}

void sum_avg(int ele ,int array[]) // for calculating sum & average
{
	float sum = 0;
	for (int i = 0; i < ele; i++)
	{
		sum += array[i];
	}		
	cout << "\t Sum  =  " << sum;
	cout << " ,\t Average  =  " << sum / ele << endl;
}

void min_max( int ele , int array[]) // for printing minimum & maximum elements
{
	int min = array[0] , max = min ;
	for(int i = 0; i < ele; i++)
	{
		if(array[i] < min)
			min = array[i];
		if(array[i] > max)
			max = array[i];
	}
	cout << "\t Minimum = " << min << " ,\t Maximum = " << max << endl;
}

int rmvDuplicate(int ele, int array[]) // for removing duplicates
{
	bool duplicate = false;
	
	for(int i = 0 ; i < ele - 1; i++)
	{
		for(int j = i+1 ; j < ele ;)
		{
			if(array[i] == array[j])
			{
				array[j] = array[ele-1];			
				ele--;
				duplicate = true;
			}
			else
				j++;
		}
	}
	if(duplicate == 0)
		cout << "\n There is no duplicate elements. \n";
	for(int i = 0; i < ele; i++)
		cout << "\t n[" << i + 1 << "]  :  " << array[i] << endl;
	return ele;
}

void revArray(int ele , int array[]) // for printing array in reverse order
{
	for(int i = ele - 1; i >= 0; i--)
		cout << "\t n[" << i+1 << "]  :  " << array[i] <<endl;
}

int main()
{	
	char choice;
	int ele , array[25];
	cout << "\n\t\t Practical 10 \n";
	cout << "\n\t  \" Operations on Array \" ";
	ele = enterArr(array);	
	do
	{	
		cout << "\n\n\n What do you want to do :  \n"
			 << "\n\t 1. Re-enter the elements "
			 << "\n\t 2. Print the even-valued elements"
			 << "\n\t 3. Print the odd-valued elements"
			 << "\n\t 4. Calculate the sum & average of the elements"
			 << "\n\t 5. Print the minimum and maximum elements"
			 << "\n\t 6. Remove the duplicate elements"
			 << "\n\t 7. Print the array in reverse order"
			 << "\n\t 8. Quit the program \n\n "
			 << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			cout << "\n\n  Re-enter the elements..... \n";
			ele = enterArr(array);
			break;

		case '2':
			cout << "\n\n  Printing the even-valued elements......\n\n";
			evenEle(ele , array);	
			break;		
			

		case '3':
			cout << "\n\n  Printing the odd-valued elements......\n\n";
			oddEle(ele , array);
			break;

		case '4':
			cout << "\n\n  Calculating sum and average......\n\n";
			sum_avg(ele , array);			
			break;

		case '5':
			cout << "\n\n  Printing the minimum & maximum......\n\n";
			min_max(ele, array);
			break;

		case '6':
			cout << "\n\n Removing the duplicates... \n\n ";
			ele = rmvDuplicate(ele, array);
			break;

		case '7':
			cout << "\n\n  Printing the array in reverse order......\n\n";
			revArray(ele , array);
			break;

		case '8':
			cout << "\n\n Quiting the program......";
			cout << "\n\n Press enter to quit ";
			cin.get();
			cin.ignore();
			break;

		default:
			cout << "\n\n Please enter a proper choice. \n";
		}	
	}while(choice != '8');
}
