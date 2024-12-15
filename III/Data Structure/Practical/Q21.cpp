#include <iostream>
#include <iomanip>
using namespace std;

bool symmetric(int *a, const int& n){
	if(a)
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(a[i*n + j] != a[j*n + i])
					return false;
		return true;
	}
	return false;
}

int main()
{
	int r,c, *m = 0;

	cout << "\n\t Practical 21 \n\n Symmetric Matrix implementation in 1D Array";

	cout << "\n\n Enter the row & column of the matrix : ";
	cin >> r >> c;

	if(r && c && r == c)
	{
		m = new int[r*c]{0};

		cout << "\n Enter the elements : ";
		for(int i = 0; i < r; i++){
			cout << "\n Row " << i+1 << " : ";
			for(int j = 0; j < c; j++)
				cin >> m[i*r + j];
		}
				

		if(symmetric(m, r))
		{
			cout << "\n\tGiven Matrix"<< right << setw(13*r)<<"Symmetric Matrix \n";

			for(int i = 0; i < r; i++)
			{
				cout << '\t';
				for (int j = 0, k = 0; j < c && k < 2; j++){
					cout << m[i*r + j] << '\t';
					if(j == c-1)
					{
						cout << '\t';
						j = -1;
						k++;
					}
				}
				cout << endl;
			}

			cout << "\n Given Matrix is symmetric !!!\n";
		}
		else
			cout << "\n Given Matrix is not symmetric !!!\n";

		
		delete[] m;
		m = 0;
	}
	else
		cout << "\n Symmetric Matrices are square matrix !!!\n";
	cout << endl;
}
