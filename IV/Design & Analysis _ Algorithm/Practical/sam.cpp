//#include <iostream>
#include "sort.hpp"

using namespace std;


void check(const uint& start, const uint& end, const uint& n)
{
    if(start >= end || n < 1)
        return;
    srand(time(NULL));

    int arr[end];
    uint len, c;

    cout << "\nLength  Sort \n";
    for(uint i = 0; i < n; i++)
    {
        len = 8;//start + rand() % (end - start);

        cout << "\n " << len << '\t';

        for(uint j = 0; j < len; j++)
            arr[j] = rand() % (start * end + j);
        c += heapSort(arr, len);
    }
    cout << c << endl;
}

int main(){    /*
    int a[] = {5,4,1,3,6,9};
    int n = size_arr(a);

    cout << "\n Unsorted Array : ";
    printArray(a,n);
    countSort(a, n);
    cout << "\n Sorted Array   : ";
    printArray(a,n);
    */
    check(1, 3000, 1);

}