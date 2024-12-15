#include <iostream>
#include "STL/queue.hpp"

using namespace std;

void details(const stl::queue_a<int>& c)
{
	cout << "\n\n Queue is empty  : " << boolalpha << c.empty();
	cout << "\n Queue is full   : " << c.full();
	cout << "\n Size  of Queue  : " << c.size();
	cout << "\n Queue's capacity: " << c.capacity();
	if(!c.empty())
	{
		cout << "\n Front of Queue  : " << c.Front();
		cout << "\n Back  of Queue  : " << c.Back() <<endl;
	}
}

int main()
{
	stl::queue_a<int> s(4);
	cout << "\n\tPractical 8\n";
	cout << "\n Queue using Circular Array(with templates) \n";

	cout << "\n Queue details at beginning : ";
	details(s);

	for(int i = 1; i <= 4; i++)
		s.enqueue(i);
	cout << "\n\n After enqueuing 1 to 4 in Queue :";
	details(s);
	cout << "\n Queue : " << s << endl;
	
	cout << "\n After dequeuing " << s.dequeue();
	cout << "\n Queue : " << s << endl;
	
	cout << "\n Queue details at the end :";
	details(s);
	cout << endl;
}