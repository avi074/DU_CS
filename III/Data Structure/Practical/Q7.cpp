#include <iostream>
#include "STL/stack.hpp"

using namespace std;

void details(const stl::stack_a<int>& c)
{
	cout << "\n\n Stack is empty  : " << boolalpha << c.empty();
	cout << "\n Stack is full   : " << c.full();
	cout << "\n Size  of Stack  : " << c.size();
	cout << "\n Stack's capacity: " << c.capacity();
	if(!c.empty())
		cout << "\n Top of Stack\t : " << c.top() <<endl;
}

int main()
{
	stl::stack_a<int> s(4);
	cout << "\n\tPractical 7\n";
	cout << "\n Stack using Arrays(with templates) \n";

	cout << "\n Stack details at beginning : ";
	details(s);
	s.push(12);
	s.push(7);
	s.push(5);
	s.push(9);
	
	cout << "\n\n After pushing 12,7,5,9 in stack s :";
	details(s);
	cout << "\n Stack s : " << s << endl;
	
	cout << "\n After poping out " << s.top();
	s.pop();
	cout << "\n stack s : " << s << endl;
	
	cout << "\n Stack details at the end :";
	details(s);
}
