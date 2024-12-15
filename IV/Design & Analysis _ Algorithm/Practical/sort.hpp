#ifndef __sort__
#define __sort__ 0x00101

#include <sys/types.h>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <c++/11/bits/stl_algo.h>

using namespace std;

#define size_arr(a) sizeof(a) / sizeof(a[0])

template <typename tp>
void swap(tp *a, tp *b)
{
    tp tmp = *a;
    *a = *b;
    *b = tmp;
}

template <typename Tp>
void printArray(Tp *a, uint n, ostream_iterator<Tp> o = ostream_iterator<Tp>(cout, " "))
{
    for (uint i = 0; i < n; i++)
        o = a[i];
}

/*************************** Insertion Sort *****************************/

template <class T, class _comp = less<T>>
uint insertionSort(T *arr, const uint &len, const _comp &cmp = _comp())
{
    uint c = 0;
    T tmp;

    if (len < 2)
        return c;

    for (int i = 1, j; i < len; i++, c++)
    {
        tmp = arr[i];

        for (j = i - 1; j >= 0 && cmp(tmp, arr[j]); j--, c++)
            arr[j + 1] = arr[j];

        arr[j + 1] = tmp;
    }
    return c;
}

/**********************************************************************/

/***************************** Heap Sort ******************************/

template <class T, typename Comp>
uint heapify(T *a, uint i, const uint &n, const Comp &cmp)
{
    uint top = i, l, r, c = 0;

    while (i < n/2)
    {
        l = 2 * i;
        r = l + 1;

        if (l < n && cmp(a[top], a[l]))
            top = l;

        if (r < n && cmp(a[top], a[r]))
            top = r;
        c += 3;
        if (top != i)
        {
            swap(a[i], a[top]);
            i = top;
        }
        else
            break;
    }

    return c;
}

template <class Tp, class _Comp = less<Tp>>
uint heapSort(Tp *a, const uint &n, const _Comp &cmp = _Comp())
{
    uint c = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, i, n, cmp);

    for (uint i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        c += heapify(a, 0, i, cmp);
    }
    return c;
}
/***********************************************************************/

/****************************** Merge Sort *****************************/

template <typename T, class _comp>
uint merge(T *arr, const uint &l, const uint &m, const uint &r, const _comp &cmp)
{
    uint n1 = m - l + 1, n2 = r - m, i, j, k;
    T L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k] = L[i++];

        else
            arr[k] = R[j++];

        k++;
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    return k - l;
}

template <typename T, class _comp = less<T>>
uint mergeSort(T *arr, const uint &begin, const uint &end, const _comp &cmp = _comp())
{
    if (begin < end)
    {
        uint mid = (begin + end) / 2;
        return mergeSort(arr, begin, mid, cmp) +
               mergeSort(arr, mid + 1, end, cmp) +
               merge(arr, begin, mid, end, cmp);
    }
    return 1;
}

/***************************************************************************/

/***************************** Quick Sort ***********************************/

template <class T, class comp>
int partition(T *arr, const int &l, const int &r, const comp &cmp)
{
    T x = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
        if (cmp(arr[j], x))
        {
            i++;
            swap(&arr[i], &arr[j]);
        }

    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}

// For Randomized Quick Sort
template <class R, class comp>
int rpartition(R *arr, const int &l, const int &r, const comp &cmp)
{
    srand(time(NULL));
    int i = l + (rand() % (r - l));
    swap(&arr[i], &arr[r]);
    return partition(arr, l, r, cmp);
}

template <class A, class comp = less<A>>
int quickSort(A *arr, const int &l, const int &r, const comp &cmp = comp())
{
    if (l < r)
    {
        int m = rpartition(arr, l, r, cmp);
        return m - l +
               quickSort(arr, l, m - 1, cmp) + quickSort(arr, m + 1, r, cmp);
    }
    return 1;
}

/***************************************************************************/

/**************************** Count Sort ***********************************/

template <class T>
void countSort(T *a, const int &len)
{
    T max = *max_element(a, a + len) + 1;
    int c[max + 1] = {0};

    for (int i = 0; i < len; i++)
        c[a[i]]++;

    for (int i = 0, j = 0; j < max + 1;)
        while(c[j]--)
            a[i++] = j;
}

/**************************************************************************/

#endif