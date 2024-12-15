#include <iostream>
#include "Sem_3/SinglyList.cpp"

using namespace std;


int main(){
    SinglyList<int> s{1,2,5,7,9}, c;
    int sum = 0;

    cout << "\nGiven list of numbers (s) : " << s << endl;

    for(int i:s){
        sum += i;
        c.push(sum);
    }
    
    cout << "\nCumulative list of s  (c) : " << c << "\n\n";
}