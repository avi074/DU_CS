#include <iostream>
using namespace std;
#define Log10 2.30258509
double ln_x(double n)
{
	short int count = 0;
	double x, loge = 0, error = 10e-10;	
	
	for(;n > 10; n /= 10) //for counting digits
		count++;
	x = (n-1)/(n+1);
	loge = count * Log10;
	if(n == 10)
		return Log10;
	else
		for(double i = x , k = 1; i > error; i *= x * x,k += 2)
			loge += 2 * i / k;	
	return loge;	
}
double e_pwr(double x)
{
	double e_x = 1 , i = 1, j = 1, k = x ;
	for(;j <= (x > 20 ? 75 : 40); k *= x, j++, i *= j)
		e_x += k / i;		
	return e_x;
}
int main()
{
	int i_pwr;
	double p_pwr, ln, e = 1;
	long double num, pwr, n_pwr = 1;
	bool inf = false , Nan = false;
	cout << "\n\t This Program calculates the power of given number. \n";
	cout << "\n Enter a number : ";
	cin >> num;
	cout << "\n Enter the power of number : ";
	cin >> pwr;
	i_pwr = pwr; // i_pwr is an integral value of power.
	p_pwr = pwr - i_pwr;// p_pwr is the decimal value of power.
	
	if(num == 0)
	{
		if(pwr < 0)
			inf = true;
		else if(pwr > 0)
			n_pwr = 0;
	}
	else if(num == 1)
		n_pwr = 1;
	else if(num < 0 && pwr != i_pwr)
		Nan = true;
	else
	{
		for(int i = 0; i != i_pwr;)
			{
				if(pwr > 0)
					n_pwr *=  num;
				else
					n_pwr *= 1.0 / num;
				pwr < 0 ? i-- : i++;
			}
		if(p_pwr != 0)
		{
			ln = ln_x(num);
			e = e_pwr(p_pwr * ln); 
		}
		n_pwr *= e;
	}
	if(inf)
		cout << "\n\t " << num<< " ^ ( " << pwr << " )  :  inf";
	else if(Nan)
		cout << "\n\t " << num<< " ^ ( " << pwr << " )  :  nan";
	else	
		cout << "\n\t " << num<< " ^ ( " << pwr << " )  :  " << n_pwr;
	
	cout << "\n\n *inf = infinity/out of range \n *nan = not a number/complex number" << endl;	
}
