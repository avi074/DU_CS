#include "sort.hpp"

using namespace std;

int main(){
    int a[] = {1,0,2,3,6,4,9,-2,5};
    int n = sizeof(a)/sizeof(a[0]);

    cout << "\nUnsorted Array: \n";
    printArray(a, n);
    
    cout << "\n\nComparisons in Insertion Sort : " << insertionSort(a, n) << endl;
    
    cout << "\nSorted array in ascending order: \n";
    printArray(a, n);
}