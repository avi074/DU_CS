#include <iostream>
#include "STL/algo.hpp"

using namespace std;
using namespace stl;

template <class T>
void print(T *arr, int n)
{
    cout << "{ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << " }" << endl;
}

void printMsg(bool indx)
{
    if (indx)
        cout << "\n Your element is present in the array !!! \n";
    else
        cout << "\n Your element is not present in the array !!! \n";
}

template <class T>
void Search_menu(T *arr, int len)
{
    T key;
    char op;

    if (arr == nullptr || len < 1)
        return;
    do
    {
        cout << "\n *************************************************\n\n Choose an option : \n\n 1. Linear Search (For Unordered Arrays)"
             << "\n 2. Binary Search (For Ascending Ordered Arrays)\n 3. Binary Search (For Descending Ordered Arrays)\n"
             << "\n Enter your option (0 for exit) : ";
        cin >> op;

        if (op != '0' && op < '4')
        {
            cout << "\n Enter the element you want to search : ";
            cin >> key;
        }
        cout << "\n *************************************************\n";

        switch (op)
        {
        case '1':
            printMsg(linearSearch(arr, arr + len, key));
            break;

        case '2':
            printMsg(binarySearch(arr, len, key));
            break;

        case '3':
            printMsg(binarySearch(arr, len, key, greater<T>()));
            break;

        default:
            if (op != '0')
                cout << "\n Invalid Input !!! \n";
        }
    } while (op != '0');
}

template <typename T = int>
T *getArray(int &len)
{
    T *a = nullptr;
    cout << "\n Enter the number of elements : ";
    cin >> len;
    if (len > 0)
    {
        a = new T[len];
        cout << "\n Enter the elements : \n";
        for (int i = 0; i < len; i++)
        {
            cout << " Element " << i + 1 << ":\t ";
            cin >> a[i];
        }
    }
    return a;
}

int main()
{
    cout << "\n\t\t\t Practical 1 \n";
    int *arr = 0, len;
    arr = getArray(len);
    cout << "\n Your array is : ";
    print(arr, len);
    Search_menu(arr, len);
    delete[] arr;
}
