#include <iostream>
#include "STL/linked_list.hpp"

using namespace std;

int main()
{
	stl::doublyList<int> d, d1{10,20,50};

	cout << "\n\t Practical 4 \n";
	cout << "\n DoublyLists :\n d  = " << d << ",\t d1 = " << d1 << endl;

	d.push_back(2);
	d.push_front(1);
	d += {3,4,5};
	cout << "\n Insertion of 1 to 5 in d :\n d = " << d << endl;

	d.remove(4);
	d.pop_front();
	d.pop_back();
	cout << "\n Deletion of {1,4,5} in d :\n d = " << d << endl;

	d.reverse();
	cout << "\n Reversing of d :\n s = " << d << endl << boolalpha; 

	cout << "\n Searching in d :\n  2 in d : " << d.search(2) 
		 << "\n 40 in d : " << d.search(40) << endl;

	d1.append(d);
	cout << "\n Appending d in d1 :\n d  = " << d 
		 << ",\t d1 = " << d1 << endl;
	
}
