#include <iostream>

using namespace std;

long fact(long n)
{
	if (n <= 1)
		return 1;
	return n * fact(n - 1);
}

long nPr(){
    int n,k;
    cout << "\n Enter the number n & k for P(n,k) : ";
    cin >> n >> k;
    if(n < k)
        return 0;
    else
        return fact(n)/fact(n-k);
}

long nCr()
{
    int n,k;
    cout << "\n Enter the number n & k for C(n,k) : ";
    cin >> n >> k;
	return fact(n) / (fact(k) * fact(n - k));
}


int main(){
    char op;
    long rslt;

    do{
        system("cls");
        cout << "\n\n *************************** \n What you want to calculate \n 1. Permutation \n 2. Combination "
        <<"\n ******************************\n Enter your Option(0 for exit) : ";
        cin >> op;
        switch (op)
        {
        case '1':
            rslt= nPr();
            cout << "\n The result is  : " << rslt ;
            break;

        case '2':
            rslt = nCr();
            cout << "\n The result is  : " << rslt ;
            break;
        default:
        if(op != '0')
            cout << "\n invalid input !!!";
        }
        cin.get();
        cin.ignore();
        
    }while(op != '0');
}