#include <iostream>
using namespace std;


int main()
{
	int r,c, *m = 0;

	cout << "\n\t Practical 18 \n\n Diagonal Matrix representation in 1D Array";

	cout << "\n\n Enter the row & column of the matrix : ";
	cin >> r >> c;

	if(r && c && r == c)
	{
		m = new int[r]{0};

		cout << "\n Enter the " << c << " diagonal elements : ";
		for(int i = 0; i < r; i++)
			cin >> m[i];

		cout << "\n Diagonal Matrix :\n";
		for(int i = 0; i < r; i++)
		{
			cout << '\t';
			for(int j = 0; j < c; j++){
				i == j ? cout << m[i] : cout << 0;
				cout << '\t';
			}
			cout << endl;
		}

		delete[]m;
		m = 0;
	}
	else
		cout << "\n Diagonal Matrix are square matrix !!!\n";
	cout << endl;
}