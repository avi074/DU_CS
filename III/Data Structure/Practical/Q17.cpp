#include <iostream>
#include "STL/stack.hpp"
#include "STL/queue.hpp"

using namespace std;
using namespace stl;

int main()
{
    cout << "\n\t Practical 17 \n";
	stack_a<int> s1{2,3,7,9,11,15,17,120,125,150};
    queue_a<int> s2(s1.size());

    cout << "\nADT = STACK(s1) / Queue(s2)\n";
    cout << "\n\t ADT\tsize  capacity \tData\n";
    cout << "\n\t s1 : \t" << s1.size() <<'\t' << s1.capacity() << '\t' << s1;
    cout << "\n\t s2 : \t" << s2.size() <<'\t' << s2.capacity() << '\t' << s2;

    while(!s1.empty())
    	s2.enqueue(s1.pop());
    cout << "\n\nAfter swapping/moving\n";
    cout << "\n\t s1 : \t" << s1.size() <<'\t' << s1.capacity() << '\t' << s1;
    cout << "\n\t s2 : \t" << s2.size() <<'\t' << s2.capacity() << '\t' << s2;

    while(!s2.empty())
        s1.push(s2.dequeue());

    cout << "\n\nAfter reversing\n";
    cout << "\n\t s1 : \t" << s1.size() <<'\t' << s1.capacity() << '\t' << s1;
    cout << "\n\t s2 : \t" << s2.size() <<'\t' << s2.capacity() << '\t' << s2 << endl;
}
