#include <iostream>
#include <cmath>

using namespace std;
#define swap(a,b) a = a+b; b=a-b; a=a-b; 

short n, *x;

void reset(){
	for(int i = 0; i < n; i++)
		x[i] = 0;
}

int sum(long digit){
	int sum = 0;
	if(n == 1)
		x[0] = digit;
	else{
		for(int i = n-1; digit != 0; digit /= 10, i--){
			x[i] = digit % 10;
			sum += x[i];
			if(sum > 10)
				break;
		}
	}
	return sum;
}

void print(){
	cout << "\n\n ";
	for(int i = 0; i < n; i++)
		cout << x[i] << "\t";
}

void printLast(){
	for(int i = 0; i <= n-1; i++){
		x[i] = 10;
		print();
		swap(x[i],x[i+1]);
	}	
}

int main(){
	float MAX,j = 0;
	
	cout << "\n Enter the number of variables : ";
	cin >> n;
	
	x = new short[n];
	reset();
	MAX = pow(10,n);
	cout << "\n This is the values of x(i) variables : ";
	for(float i = 0; i <= MAX; i++){
		if(sum(i) <= 10)
			print();
	}
	reset();
	printLast();	
	cin.get();
	cin.ignore();
}