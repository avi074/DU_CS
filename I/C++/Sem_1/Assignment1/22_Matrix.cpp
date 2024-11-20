#include <iostream>
using namespace std;

void sum(int m, int n, float m1[][10], float m2[][10])
{
	int m3[m][5] = {0}, r, c;

	cout << "\n After adding these two matrices, \n\n Your new matrix is : \t";
	for (r = 0; r < m; r++)
	{
		for (c = 0; c < n; c++)
		{
			m3[r][c] = m1[r][c] + m2[r][c];
			cout << m3[r][c] << "\t";
		}
		cout << endl << "\t\t\t";
	}
}

void diff(int m, int n, float m1[][10], float m2[][10])
{
	int m3[m][5] = {0}, r, c;

	cout << "\n After subtracting these two matrices, \n\n Your new matrix is : \t";
	for (r = 0; r < m; r++)
	{
		for (c = 0; c < n; c++)
		{
			m3[r][c] = m1[r][c] - m2[r][c];
			cout << m3[r][c] << "\t";
		}
		cout << endl << "\t\t\t";
	}
}

void cross(int m, int n, float mat1[][10])
{
	short int m1, n1;
	float mat2[10][10], mat3[10][10];
	bool non_valid;
	do
	{
		non_valid = false;
		cout << "\n Enter the size of Second Matrix (Row Column) : ";
		cin >> m1 >> n1;
		if (m <= 0 || n <= 0)
		{
			cerr << "\n Please enter right size of matrix. \n";
			non_valid = true;
		}
		if (n != m1)
		{
			cerr << "\n Multiplication of these two matrices is undefined. \n";
			non_valid = true;
		}
	} while (non_valid);
	
	cout << "\n Enter the elements... " << endl;
	cout << "\n Row no.   Column No.  Elements" << endl;
	for (int i = 0; i < m1; i++)
	{
		cout << " \n  " << i + 1;
		for (int j = 0; j < n1; j++)
		{
			cout << "\t\t" << j + 1 << "\t  ";
			cin >> mat2[i][j];
		}
	}
	cout << "\n After multiplication these two matrices, \n\n Your new matrix is : \t";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			mat3[i][j] = 0;
			for (int k = 0; k < n; k++)
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			cout << mat3[i][j] << "\t";
		}
		cout << endl<< "\t\t\t";
	}
}

int main()
{
	short int m, n;
	float mat1[10][10], mat2[10][10];
	char ch;

	cout << "\t\t Calculations on Matrix \n";
	do
	{
		cout << "\n Enter the size of First Matrix (Row Column) : ";
		cin >> m >> n;
		if (m <= 0 || n <= 0)
			cerr << "\n Please enter right size of matrix. \n";
	} while (m <= 0 || n <= 0);

	cout << "\n Enter the elements... " << endl;
	cout << "\n Row no.   Column No.  Elements" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << " \n  " << i + 1;
		for (int j = 0; j < n; j++)
		{
			cout << "\t\t" << j + 1 << "\t  ";
			cin >> mat1[i][j];
		}
	}

	cout << "\n\n What you want to do ....\n\n 1. Addition \n 2. Subtract \n 3. Multiplication \n";
	cout << "\n Enter your choice : ";
	cin >> ch;

	if (ch == '1' || ch == '2')
	{
		cout << "\n Enter the Second matrix..." << endl;
		cout << "\n Row no.   Column No.  Elements" << endl;
		for (int i = 0; i < m; i++)
		{
			cout << " \n  " << i + 1;
			for (int j = 0; j < n; j++)
			{
				cout << "\t\t" << j + 1 << "\t  ";
				cin >> mat2[i][j];
			}
		}
	}
	switch (ch)
	{
	case '1':
		sum(m, n, mat1, mat2);
		break;
	case '2':
		diff(m, n, mat1, mat2);
		break;
	case '3':
		cross(m, n, mat1);
		break;
	default:
		cout << "\n\n Invalid input.\n";
	}
}
