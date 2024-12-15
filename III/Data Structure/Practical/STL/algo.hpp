#ifndef __algo__
#define __algo__ "algo"

#define check()                 \
    if (start == 0 || end == 0) \
        std::__throw_logic_error("Iterators can't be NULL !!!");

#define check_sort()  \
    //check();          \
    if (start == end) \
        return;

#include <iterator>

namespace stl
{

    // Bubble Sort
    template <class FI, typename _compare = std::less<typename std::iterator_traits<FI>::value_type>>
    void bubbleSort(FI start, FI end, _compare cmp = _compare())
    {
        check_sort();
        FI j;

        while (start != end)
        {
            for (j = start + 1; j != end; j++)
                if (cmp(*j, *start)) // checking *j < *start
                    std::swap(*start, *j);
            start++;
        }
    }

    // Insertion Sort
    template <class RI, class _compare = std::less<typename std::iterator_traits<RI>::value_type>>
    void insertionSort(RI start, RI end, _compare cmp = _compare())
    {
        check_sort();
        RI i, j;

        for (i = start + 1; i != end; i++)
        {
            auto tmp = *i;
            for (j = i - 1; j >= start && cmp(tmp, *j); j--)
                *(j + 1) = *j;
            *(j + 1) = tmp;
        }
    }

    // Selection Sort
    template <class FI, class _compare = std::less<typename std::iterator_traits<FI>::value_type>>
    void selectionSort(FI start, FI end, _compare cmp = _compare())
    {
        check_sort();

        FI m, i;
        while (start != end)
        {
            m = start;
            for (i = start + 1; i != end; i++)
                if (cmp(*i, *m))
                    m = i;

            if (m != start)
                std::swap(*start, *m);
            start++;
        }
    }

    // Linear Search
    template <class II, class T = typename std::iterator_traits<II>::value_type>
    bool linearSearch(II start, II end, const T &key)
    {
        check();
        while (start != end)
        {
            if (*start == key)
                return true;
            start++;
        }
        return false;
    }

    // Binary Search
    template <class T, class _compare = std::less<T>>
    bool binarySearch(T *arr, int n, const T &key, _compare cmp = _compare())
    {
        int l = 0, mid;
        n = n - 1;
        if (arr)
            while (l <= n)
            {
                mid = (l + n) / 2;

                if (arr[mid] == key)
                    return true;

                else if (cmp(arr[mid], key))
                    l = mid + 1;
                else
                    n = mid - 1;
            }
        return false;
    }
};
#endif