#include <iostream>
#include "Sem_3/SinglyList.cpp"

using namespace std;

void set(NODE<int>* a, NODE<int>* b){
    while(a && b){
        a->next = b->next;
        a = a->next;
        if(a)
            b->next = a->next;
        b = b->next;
    }
}

int main(){
    SinglyList<int> s1{1,2,3,4,5};
    
    cout << "\nGiven List of numbers \t\t : " << s1 << endl;

    NODE<int>* o = s1.begin().base();
    NODE<int>* e = s1.begin().base()->next;
    s1.reset(); // To stop double deletion of a node
    set(o,e);   
    
    SinglyList<int> s2(o);
    SinglyList<int> s3(e);

    cout << "\nList of odd nodes of given list  : " << s2 << endl;
    cout << "\nList of even nodes of given list : " << s3 << endl << endl;
}