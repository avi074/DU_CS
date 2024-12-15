#include <iostream>
using namespace std;

int sum(int n)
{
	int sum = 0;
	while(n)
		sum += n--;
	return sum;
}


int main()
{
	int r,c, *m = 0;

	cout << "\n\t\tPractical 19 \n\n Lower Triangular Matrix representation in 1D Array";

	cout << "\n\n Enter the row & column of the matrix : ";
	cin >> r >> c;

	if(r && c && r == c)
	{
		c = sum(r);
		m = new int[c]{0};

		cout << "\n Enter the " << c << " lower triangular elements : ";
		for(int i = 0; i < c; i++)
			cin >> m[i];

		cout << "\n Lower Triangular Matrix :\n";
		for(int i = 0, k = 0; i < r; i++)
		{
			cout << '\t';
			for(int j = 0; j < r; j++){
				j <= i ? cout << m[k++] : cout << 0;
				cout << '\t';
			}
			cout << endl;
		}

		delete[]m;
		m = 0;
	}
	else
		cout << "\n Lower Triangular Matrix are square matrix !!!\n";
	cout << endl;
}
