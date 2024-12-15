#include "algo.hpp"

using namespace algo;

int main()
{
    int a[] = {5,13,2,25,7,17,20,8,4};
    int n = sizeof(a)/sizeof(a[0]);

    cout << "\n\t\t Practical 2\n\t\t  Heap Sort\n";

    cout << "\n Unsorted Array: \n";
    printArray(a, n);

    cout << "\n Comparisons in Heap Sort : " << heapSort(a, n, greater<int>()) << endl;
    
    cout << "\n Sorted array in descending order: \n";
    printArray(a, n);
}