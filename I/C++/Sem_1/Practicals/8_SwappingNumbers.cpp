 /*********************************************************************************************************
 This programs swaps the given numbers using macro.
 
 input --> x = 123 , y = 456
 output --> x = 456 , y = 123
 
 for swapping we can use temperory variable or we can use this trick :-
 1 . store the sum of the values in one variable  { x = x + y}
 2 . After it substract another variable from summation { y = x - y  = (x + y) - y = x}
 3 . last  again substract but this time we get second variable { x = x - y = (x + y) - (x) = y}
 *********************************************************************************************************/

#include <iostream>
using namespace std;

#define swap(x,y) x = x + y , y = x - y , x = x - y; // swap(x,y) is macro.

int main()
{
    float num1 , num2;
    cout << "\n\t\t\t  Practical 8 " ; 
	cout << "\n\t\t   Swapping using macro" << endl;
	
    cout << "\n Enter the first number : ";
    cin >> num1;
    cout << "\n Enter the second number : ";
    cin >> num2;
    
    swap(num1 , num2); // calling macro
    
    cout << "\n\t After Swapping.... " << endl;
    cout << "\n First number = " << num1 << endl << "\n Second number = " << num2 << endl;
}
