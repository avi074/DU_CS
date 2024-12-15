#include <iostream>
#include "sort.hpp"

using namespace std;

int main(){

    int a[] = {5,1,2,0,3,4,8,9,6};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "\nUnsorted Array: \n";
    printArray(a, n);
    
    cout << "\n\nComparisons in Merge Sort : " << mergeSort(a, 0, n - 1) << endl;
    
    cout << "\nSorted array in ascending order: \n";
    printArray(a, n);
}