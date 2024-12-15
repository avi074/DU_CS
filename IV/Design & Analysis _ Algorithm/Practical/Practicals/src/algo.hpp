#ifndef _algo_hpp_
#define _algo_hpp_

#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

namespace algo
{
    template <class T>
    void printArray(T *array, const uint &len)
    {
        cout << "\n { ";
        for (uint i = 0; i < len - 1; i++)
            cout << array[i] << ", ";
        cout << array[len - 1] << " }\n";
    }

    template <class T>
    void swap(T *a, T *b)
    {
        T tmp = *a;
        *a = *b;
        *b = tmp;
    }

    /*      Insertion Sort      */
    template <class Tp, class _Comp = less<Tp>>
    uint insertionSort(Tp *array, const uint &len, const _Comp &cmp = _Comp())
    {
        uint count = 0;
        Tp key;
        if (len > 1)
            for (int i = 1, j = 0; i < len; i++)
            {
                j = i - 1;
                key = array[i];
                while (j >= 0 && cmp(key, array[j]))
                {
                    array[j + 1] = array[j];
                    j--;
                    count++;
                }
                array[j + 1] = key;
                count++;
            }
        return count;
    }

    /*      Merge Sort      */
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
            if (cmp(L[i], R[j]))
                arr[k] = L[i++];

            else
                arr[k] = R[j++];

            k++;
        }

        while (i < n1)
            arr[k++] = L[i++];

        while (j < n2)
            arr[k++] = R[j++];

        return k - l - 1;
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

    /*       Heap Sort      */
    template <class T, class _Comp>
    void heapify(T array[], const int &i, const uint &len, const _Comp &cmp, uint &count)
    {
        uint left, right, top = i;
        left = 2 * i + 1;
        right = 2 * i + 2;

        ;
        if (left < len && cmp(array[top], array[left]))
            count++, top = left;

        ;
        if (right < len && cmp(array[top], array[right]))
            count++, top = right;

        ;
        if (top != i)
        {
            swap(array + i, array + top);
            count++;
            heapify(array, top, len, cmp, count);
        }
    }

    template <class Tp, class _Comp = less<Tp>>
    uint heapSort(Tp *array, const uint &len, const _Comp &cmp = _Comp()) // Recursive Version
    {
        uint count = 0; // Counter
        // Build a Heap
        for (int i = len / 2 - 1; i >= 0; i--)
            heapify(array, i, len, cmp, count);

        // One by one extract an element from heap
        for (uint i = len - 1; i > 0; i--)
        {
            // Move current root to end
            swap(array, array + i);

            // call heapify on the reduced heap
            heapify(array, 0, i, cmp, count);
        }
        return count;
    }

    template <class Tp, class _Comp = less<Tp>>
    uint i_heapSort(Tp *array, const uint &len, const _Comp &cmp = _Comp()) // Iterative Version
    {
        uint count = 0, i;
        int j, index;
        // Build a Heap
        for (i = 1; i < len; i++)
        {
            for (j = i; cmp(array[(j - 1) / 2], array[j]); j = (j - 1) / 2, count++)
                swap(array + j, array + (j - 1) / 2);
        }
        // Sort the Heap
        for (i = len - 1; i > 0; i--)
        {
            swap(array + i, array);
            j = 0;

            do
            {
                index = 2 * j + 1;

                if (index < (i - 1) && cmp(array[index], array[index + 1]))
                    index++, count++;

                if (index < i && cmp(array[j], array[index]))
                    swap(array + index, array + j), count++;

                j = index;
            } while (index < i);
        }
        return count;
    }

    /*            Quick Sort           */
    template <class T, class _Comp>
    int partition(T *array, const int &start, const int &end, const _Comp &cmp)
    {
        T x = array[end];
        int i = start;

        for (int j = start; j < end; j++)
            if (cmp(array[j], x))
            {
                swap(array + j, array + i);
                i++;
            }
        swap(&array[i], array + end);
        return i;
    }

    template <class T, class _Comp>
    int random_partition(T *array, const int &start, const int &end, const _Comp &cmp)
    {
        srand(time(NULL));
        swap(&array[start + rand() % (end - start + 1)], &array[end]);
        return partition(array, start, end, cmp);
    }

    template <class T, class _Comp = less<T>>
    uint quickSort(T *array, const int &start, const int &end, const _Comp &cmp = _Comp())
    {
        if (start < end)
        {
            int piv = partition(array, start, end, cmp);
            return (piv - start) +
                   quickSort(array, start, piv - 1, cmp) +
                   quickSort(array, piv + 1, end, cmp);
        }
        return 1;
    }

    template <class T, class _Comp = less<T>>
    uint random_quickSort(T *array, const int &start, const int &end, const _Comp &cmp = _Comp())
    {
        if (start < end)
        {
            int piv = random_partition(array, start, end, cmp);
            return (piv - start) +
                   random_quickSort(array, start, piv - 1, cmp) +
                   random_quickSort(array, piv + 1, end, cmp);
        }
        return 1;
    }

    /*       Randomized Select       */
    template <typename tp, class _Comp = less<tp>>
    tp randomizedSelect(tp *array, const int &start, const int &end, const int &i, const _Comp &cmp = _Comp())
    {
        if (i <= 0)
            __throw_invalid_argument("Index Error : Index starts with 1 not from 0 or negative !!!");

        if (start == end)
            return array[start];

        int piv = random_partition(array, start, end, cmp);
        int k = piv - start + 1;

        if (i == k)
            return array[piv];

        else if (i < k)
            return randomizedSelect(array, start, piv - 1, i, cmp);

        else
            return randomizedSelect(array, piv + 1, end, i - k, cmp);
    }

}
#endif