#include <iostream>
#include <cmath>

using namespace std;

int main(){
    short n, x,*f;
    long rslt = 0;

    cout << "\n Enter the degree of the polynomial equation : ";
    cin >> n;
    cout << "\n Enter the coefficents of the polynomial in ascending degree order : ";
    f = new short[n+1];
    for(int i = 0; i <= n; i++)
        cin >> f[i];
    cout << " \n Your equation is : ";
    for (short i = n; i != -1; i--)
    {
        if(i > 1)
            cout << f[i] << "x^" << i << " + ";
        else if (i == 1)
            cout << f[i] << "x + ";
        else
            cout <<f[i];
    }
    
    cout << "\n Enter the value of x : " ;
    cin >> x; 
    for(int i = n; i != -1; i--)
        rslt += f[i] * pow(x,i);   
    cout << "\n Result is : "<< rslt << endl ;
	cin.get();
cin.ignore();
}