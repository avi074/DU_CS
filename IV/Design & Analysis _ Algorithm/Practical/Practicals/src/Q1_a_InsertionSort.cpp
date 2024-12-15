#include "algo.hpp"

using namespace algo;

int main()
{
    int a[] = {1, 0, 2, 3, 6, 4, 9, -2, 5};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "\n\t\t  Practical 1\n\t\tA. Insertion Sort\n";

    cout << "\n Unsorted Array: \n";
    printArray(a, n);

    cout << "\n Comparisons in Insertion Sort : " << insertionSort(a, n) << endl;

    cout << "\n Sorted array in ascending order: \n";
    printArray(a, n);
}