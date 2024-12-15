#include <iostream>
#include "STL/heap.hpp"

using namespace std;
using namespace stl;

void details(const heap<int>& c)
{
	cout << "\n\n Heap is empty  : " << boolalpha << c.empty();
	cout << "\n Heap is full   : " << c.full();
	cout << "\n Size  of Heap  : " << c.size();
	cout << "\n Heap's capacity: " << c.capacity();
	if(!c.empty())
		cout << "\n Top of Heap\t : " << c.getTop() <<endl;
}

int main()
{
	heap<int> s;
	cout << "\n\tPractical 24\n";
	cout << "\n Heap (with templates) \n";

	cout << "\n Heap details at beginning : ";
	details(s);
	s.insert(12);
	s.insert(7);
	s.insert(5);
	s.insert(9);
	
	cout << "\n\n After pushing 12,7,5,9 in Heap s :";
	details(s);
	cout << "\n Heap s : " << s << endl;
	
	cout << "\n After poping out the Top" << s.extractTop();
	cout << "\n Heap s : " << s << endl;
	
	cout << "\n Heap details at the end :";
	details(s);

}
