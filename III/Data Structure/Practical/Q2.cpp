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

template <typename _tp>
void sort_menu(_tp *arr, int len)
{
    char op, way;

    if (arr == nullptr || len < 2)
        return;
    do
    {
        cout << "\n ********************************************************************** \n\n Choose an option : \n"
             << "\n\t 1. Bubble Sort \n\t 2. Insertion Sort \n\t 3. Selection Sort \n"
             << "\n Enter your option (0 for exit) : ";
        cin >> op;
        cin.ignore();
        if (op != '0' && op < '4')
        {
            cout << "\n You want to sort in ?? (1 for ascending, else descending) : ";
            cin >> way;
        }
        cout << "\n ********************************************************************** \n";

        switch (op)
        {
        case '1':
            way == '1' ? bubbleSort(arr, arr + len) : bubbleSort(arr, arr + len, greater<_tp>());
            break;

        case '2':
            way == '1' ? insertionSort(arr, arr + len) : insertionSort(arr, arr + len, greater<_tp>());
            break;

        case '3':
            way == '1' ? selectionSort(arr, arr + len) : selectionSort(arr, arr + len, greater<_tp>());
            break;

        default:
            if (op != '0')
                cout << "\n Invalid Input !!! \n";
        }

        if (op != '0' && op < '4')
        {
            cout << "\n Your sorted array is : \n\n ";
            print(arr, len);
        }
        cin.ignore();
    } while (op != '0');
}

template <typename T = int>
T *getArray(int &len)
{
    T *a = 0;
    cout << "\nEnter the number of elements : ";
    cin >> len;
    if (len > 0)
    {
        a = new T[len];
        cout << "\nEnter the elements : \n";
        for (int i = 0; i < len; i++)
        {
            cout << "Element " << i + 1 << " : ";
            cin >> a[i];
        }
    }
    else
        cout << "\n Invalid value !!!";
    return a;
}

int main()
{
    int *a, n;

    cout << "\n\t\t\tPractical 2 \n";

    a = getArray(n);
    cout << "\n Your array is : ";
    print(a, n);

    sort_menu(a, n);
    
    delete[] a;
}