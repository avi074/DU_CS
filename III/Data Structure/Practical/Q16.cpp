#include <iostream>
#include "STL/stack.hpp"

using namespace std;
using namespace stl;

template<class T>
void copy_same(stack_a<T>& a, stack_a<T>& b){
    if(a.empty())
        return;
    else{
        T var = a.pop();
        copy_same(a,b);
        b.push(var);
    }
}

int main(){
    cout << "\n\t Practical 16 \n";
    stack_a<int> s1{2,3,7,9,11,15,17,120,125,150};
    stack_a<int> s2(s1.size());

    cout << "\n\tStack  size  capacity \tData\n";
    cout << "\n\t s1 : \t" << s1.size() <<'\t' << s1.capacity() << '\t' << s1;
    cout << "\n\t s2 : \t" << s2.size() <<'\t' << s2.capacity() << '\t' << s2;

    //s1.swap(s2);
    copy_same(s1,s2);
    cout << "\n\nAfter swapping/moving\n";
    cout << "\n\t s1 : \t" << s1.size() <<'\t' << s1.capacity() << '\t' << s1;
    cout << "\n\t s2 : \t" << s2.size() <<'\t' << s2.capacity() << '\t' << s2;

    while(!s2.empty())
        s1.push(s2.pop());

    cout << "\n\nAfter reversing\n";
    cout << "\n\t s1 : \t" << s1.size() <<'\t' << s1.capacity() << '\t' << s1;
    cout << "\n\t s2 : \t" << s2.size() <<'\t' << s2.capacity() << '\t' << s2 << endl;
}
