#include "sort.hpp"

using namespace std;

int main()
{
    int a[] = {5,13,2,25,7,17,20,8,4};
    int n = sizeof(a)/sizeof(a[0]);

    cout << "\nUnsorted Array: \n";
    printArray(a, n);

    cout << "\n\nComparisons in Heap Sort : " << heapSort(a, n) << endl;
    
    cout << "\nSorted array in ascending order: \n";
    printArray(a, n);

    cout<<"\nH\v\be\v\bl\v\bl\v\bo";
}