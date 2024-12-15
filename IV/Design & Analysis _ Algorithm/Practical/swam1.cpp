#include "sort.hpp"
using namespace std;

template <class T>
void find_min_max(T *a, const uint &n, T &min, T &max)
{
    min = max = a[0];
    for (uint i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];

        if (a[i] > max)
            max = a[i];
    }
}

template <class T = int, class comp = less<T>>
void CountSort(T *a, const uint &n, comp cmp = comp())
{
    T min, max;
    find_min_max(a, n, min, max);
    cout << "\n Min : " << min << "\tMax : " << max << endl;

    T c[max] = { 0 };
    
    for(uint i = 0; i < n; i++)
        c[a[i]]++;

    for(uint i = 0; i < max; i++)
    {
        while(c[i])
        {
            
        }
    }

}

int main()
{
    int a[] = {3, 5, 7, 8, 9, 1};
    int n = sizeof(a) / sizeof(a[0]);

    CountSort(a, n);
}