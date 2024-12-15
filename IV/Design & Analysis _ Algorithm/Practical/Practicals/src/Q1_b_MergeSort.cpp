#include "algo.hpp"

using namespace algo;

int main()
{

    int a[] = {5, 10, 2, 0, 3, 4, 8, 9, 6};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "\n\t\t Practical 1\n\t\tB. Merge Sort\n";

    cout << "\n Unsorted Array: \n";
    printArray(a, n);

    cout << "\n Comparisons in Merge Sort : " << mergeSort(a, 0, n - 1) << endl;

    cout << "\n Sorted array in ascending order: \n";
    printArray(a, n);
}