#include <iostream>
#include "STL/deque.hpp"

using namespace std;

void details(const stl::deque<int>& c)
{
	cout << "\n\n Deque is empty  : " << boolalpha << c.empty();
	cout << "\n Size  of Deque  : " << c.size() << endl;
	if(!c.empty())
	{
		cout << " Front of Deque  : " << c.front();
		cout << "\n Back  of Deque  : " << c.back() << endl;
	}
}

int main()
{
	stl::deque<int> s;
	cout << "\n\tPractical 9\n";
	cout << "\n Deque using Linked List \n";

	cout << "\n Deque details at beginning : ";
	details(s);

	for(int i = 1; i <= 4; i++)
		s.push_front(i);

	cout << "\n\n After enqueuing(at front) 1 to 4 in Deque :";
	cout << "\n Deque : " << s << endl;

	for(int i = 5; i <= 8; i++)
		s.push_back(i);

	cout << "\n After pushing(at end) 5 to 8 in Deque :";	
	cout << "\n Deque : " << s << endl;

	s.pop_front();
	cout << "\n After popping out from the front :";
	cout << "\n Deque : " << s << endl;

	s.pop_back();
	cout << "\n After popping out from the end :";
	cout << "\n Deque : " << s << endl;
	
	cout << "\n Deque details at the end :";
	details(s);
	cout << endl;
}
