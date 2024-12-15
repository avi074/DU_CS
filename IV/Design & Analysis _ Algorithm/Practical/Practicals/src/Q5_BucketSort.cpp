#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(float *array, const uint &len)
{
    cout << "\n { ";
    for (uint i = 0; i < len - 1; i++)
        cout << array[i] << ", ";
    cout << array[len - 1] << " }\n";
}

int main()
{
    vector<float> hash[10];
    float a[] = {0.01, 0.23, 0.13, 0.11, 0.25, 0.35, 0.42, 0.02, 0.9, 0.45, 0.05};
    int n = sizeof(a) / sizeof(a[0]), j = 0;

    cout << "\n\t\t\t Practical 5\n\t\t\t Bucket Sort\n";

    cout << "\n Unsorted Array: \n";
    printArray(a, n);

    // Bucket Sort
    for (float &i : a)
        hash[int(i * 10)].push_back(i);

    for (vector<float> &v : hash)
            sort(v.begin(), v.end());

    for (vector<float> &v : hash)
        for (float &f : v)
            a[j++] = f;

    cout << "\n After applying bucket-sort on the array\n"
         << "\n Sorted array in ascending order: \n";
    printArray(a, n);
}