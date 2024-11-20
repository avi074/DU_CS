// This program calculates area & circumference of circle with given radius.
#include <iostream>

using namespace std;
#define pi 3.1415926535897932384626433832795  // pi value
void Circle(float r, float &C , float &A)
{
	C = 2 * pi * r;
	A = pi * r * r; 
}

int main(){
	float r , Area , Circmfrn;// r = radius
	cout<<"\n\t Circle Circumference & Area Calculator\n\n";
	cout<<" Enter Circle's radius : ";
	cin>>r;
	Circle(r,Circmfrn,Area);	
	cout<<"\n Circle's Circumference : " << Circmfrn;
	cout<<"\n\n Circle's Area : " << Area << endl;
}
