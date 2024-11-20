#include <iostream>

using namespace std;
// for counting no. of occurences
void occur(string a, string &full)
{
	int len = a.size(), n[len] = {0};
	
	for(int i = 0; i < len; i++)
	{
		for(int j = i; j < full.size(); j++)
		{
			if(a[i] == full[j])
			{
				full[j] = 0;
				n[i]++;
			}			
		}
		if(n[i])
			cout << "\n \t   " << a[i] << "\t\t\t" << n[i];
	}	
}

int main(int argc, char* argv[])
{
	string str = "";

	if(argc == 1)	// if user only enter program name
		cout << "\n You entered nothing for processing. \n";
	else
	{
		cout << "\n You entered : ";
		// save all arguments in a string.
		for(int i = 1; i < argc; i++)
		{
			cout << argv[i] << " ";
			str +=  argv[i];
		}
		cout << "\n\n\t Letter \t no. of occurences \n";
		// send arguments one by one to the function
		for(int i = 1; i < argc; i++)
			occur(argv[i], str);
		cout << endl << endl;		
	}
}
