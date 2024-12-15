#include "algo.hpp"

using namespace algo;

int main()
{
    int a[] = {5, 3, 2, 7, 1, 0, 8, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int loc;

    cout << "\n\t\t Practical 6\n\t Randomized Select Algorithm\n";

    cout << "\n Unsorted Array: \n";
    printArray(a, n);

    loc = randomizedSelect(a, 0, n - 1, 1);
    cout << "\n Finding minimum element at position 1 : " << loc << "\n\n Now Array is : \n";
    printArray(a, n);

    loc = randomizedSelect(a, 0, n - 1, 7);
    cout << "\n Finding minimum element at position 7 : " << loc << "\n\n Now Array is : \n";
    printArray(a, n);
}