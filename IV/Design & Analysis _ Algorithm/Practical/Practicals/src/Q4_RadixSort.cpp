#include "algo.hpp"

using namespace algo;

int getMax(int *array, const uint &len)
{
    int max = array[0];
    for (uint i = 1; i < len; i++)
        if (max < array[i])
            max = array[i];
    return max;
}

void countSort(int *array, const uint &len, const uint &exp)
{
    int i, *count = new int[10]{0}, *out = new int[len];

    for (i = 0; i < len; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = len - 1; i >= 0; i--)
    {
        out[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < len; i++)
        array[i] = out[i];

    delete out;
    delete count;
}

void radixSort(int *array, const uint &len)
{
    uint max = getMax(array, len);
    for (uint i = 1; (max / i) > 0; i *= 10)
        countSort(array, len, i);
}

int main()
{
    int a[] = {10, 1, 20, 300, 5, 7, 4, 1024, 995, 87};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "\n\t\t Practical 4\n\t\t Radix Sort\n";

    cout << "\n Unsorted Array: \n";
    printArray(a, n);

    radixSort(a, n);
    cout << "\n After applying Radix Sort on the Array :\n";

    cout << "\n Sorted array in ascending order: \n";
    printArray(a, n);
    
}