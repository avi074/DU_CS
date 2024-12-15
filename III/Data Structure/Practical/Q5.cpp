#include <iostream>
#include "STL/linked_list.hpp"

using namespace std;

int main()
{
	stl::circularList<int> d, d1{10,20,50};

	cout << "\n\t Practical 5\n";
	cout << "\n CiruclarLists :\n d  = " << d << ",\t d1 = " << d1 << endl;

	d.push_back(4);
	d.push_front(3);
	d += {5,6,7,8};
	cout << "\n Insertion of 3 to 8 in d :\n d = " << d << endl;

	d.remove(4);
	d.pop_front();
	d.pop_back();
	cout << "\n Deletion of {3,4,8} in d :\n d = " << d << endl;

	d.reverse();
	cout << "\n Reversing of d :\n s = " << d << endl << boolalpha; 

	cout << "\n Searching in d :\n 5 in d : " << d.search(5) 
		 << "\n 0 in d : " << d.search(0) << endl;
}
