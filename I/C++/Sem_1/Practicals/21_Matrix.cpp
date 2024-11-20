#include <iostream>

using namespace std;

class matrix
{
	int r, c;
	float **d_m = NULL;
	
	public:
		matrix(int , int);
		void set_v();
		void print();
		void sum();
		void diff();
		void cross();
		void transpos();
		~matrix();
};

matrix::matrix(int a, int b)
{
	r = a;
	c = b;
	// creating a dynamic array
	d_m = new float*[r];
	for(int i = 0; i < r; i++)
		d_m[i] = new float[c];
		
	// initialising 0 to 2D array
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			d_m[i][j] = 0;
}

void matrix::set_v()
{
	cout << "\n Enter the values of matrix ....\n";
	for(int i = 0; i < r; i++)
	{
		cout << "\n Row " << i+1 << "  -> \t";
		for(int j = 0; j < c; j++)
			cin >> d_m[i][j];			
	}	
}

void matrix::print()
{
	cout << "\n Your resultant matrix is : ";
	for(int i = 0; i < r; i++)
	{
		cout << "\t";
		for(int j = 0; j < c; j++)
			cout << d_m[i][j] << "\t";	
		cout << "\n\t\t\t";	
	}	
}

void matrix::sum()
{
	int a, b;
	cout << "\n Enter the size of second matrix (row column) : ";
	cin >> a >> b;
	
	if(r != a || c != b)
		cout << "\n\n Sum of different size matrices are undefined.\n";
	else
	{
		matrix a2(a,b);
		a2.set_v();
		// final 2D array
		matrix a3(r, c);
		// calculations
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				a3.d_m[i][j] = d_m[i][j] + a2.d_m[i][j];
		a3.print();
	}
}

void matrix::diff()
{
	int a, b;
	cout << "\n Enter the size of second matrix (row column) : ";
	cin >> a >> b;	

	if(r != a || c != b)
		cout << "\n\n Subtraction of different size matrices are undefined.\n";
	else
	{
		matrix a2(a,b);
		a2.set_v();
		// final 2D array
		matrix a3(r, c);
		// calculations
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				a3.d_m[i][j] = d_m[i][j] - a2.d_m[i][j];
		a3.print();
	}
}

void matrix::cross()
{
	int a, b;
	cout << "\n Enter the size of second matrix (row column) : ";
	cin >> a >> b;

	if(a != c)
	{
		cout << "\n\n Cross of different size matrices are undefined.\n";
		return;
	}
	else
	{
		matrix a2(a,b);
		a2.set_v();
		// final 2D array
		matrix a3(r, a2.c);
		// calculations
		for(int i = 0; i < r; i++)
			for(int j = 0; j < a2.c; j++)
				for(int k = 0; k < c; k++)
					a3.d_m[i][j] += d_m[i][k] * a2.d_m[k][j];
		a3.print();
	}
}

void matrix::transpos()
{
	matrix a2(c,r);
	
	for(int i = 0; i < c; i++)
		for(int j = 0; j < r; j++)
			a2.d_m[i][j] = d_m[j][i];
	cout << "\n After transpos...";
	a2.print();	
}

matrix::~matrix()
{
	for(int i = 0; i < r; i++)
		delete d_m[i];
	delete[] d_m;
}

int main()
{
	int row, col;
	char op;
	
	cout << "\n\t\t\t Practical 21 \n";
	cout << "\t\t   Calculations on Matrix \n";
	cout << "\n Enter the size of First matrix (row column) : ";
	cin >> row >> col;
	// creating a matrix
	matrix a1(row, col);
	a1.set_v();
	do
	{
		cout << "\n ========================================================================";
		cout << "\n Choose an option... \n\n\t 1. Addition \n\t 2. Subtract \n\t 3. Multiplication \n\t 4. Transpose \n\t 5. Quit";
		cout << "\n\n Enter your choice : ";
		cin >> op;
		cout << " ==========================================================================";
		switch(op)
		{
			case '1':
				cout << "\n ....................Addition of two matrices.................... \n";
				a1.sum();
				continue;
				
			case '2':
				cout << "\n ...................Subtraction of two matrices.................. \n";
				a1.diff();
				continue;
				
			case '3':
				cout << "\n ..................Multiplication of two matrices................ \n";
				a1.cross();
				continue;
				
			case '4':
				cout << "\n ......................Transpos the matrix....................... \n";
				a1.transpos();
				continue;
				
			default:
				if(op != '5')
					cout << "\n\n Invalid input.";
		}
	}while(op != '5');
}
