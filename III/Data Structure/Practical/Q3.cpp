#include <iostream>
#include "STL/linked_list.hpp"

using namespace std;


int main()
{
	stl::singlyList<int> s, s1{12,22,56}, s2{};

	cout << "\n\t Practical 3 \n";
	cout << "\n SinglyLists :\n s  = " << s << ",\ts1 = " << s1 
		 << ",\ts2 = " << s2 << endl;

	s.push_back(2);
	s.push_front(1);
	s += {3,4,5,6,7};
	cout << "\n Insertion of 1 to 7 in s :\n s = " << s << endl;

	s.remove(4);
	s.pop_front();
	s.pop_back();
	cout << "\n Deletion of {1,4,7} in s :\n s = " << s << endl;

	s.reverse();
	cout << "\n Reversing of s :\n s = " << s << endl << boolalpha; 

	cout << "\n Searching in s :\n  6 in s : " << s.search(6) 
		 << "\n 16 in s : " << s.search(16) << endl;

	s.append(s1);
	cout << "\n Appending s1 in s :\n s  = " << s 
		 << "\n s1 = " << s1 << endl;

	s2 = s1 + s;
	cout << "\n After operation s2 = s1 + s :\n s  = " << s 
		 << ",\ts1 = " << s1 << ",\n s2 = " << s2 << endl;
}
