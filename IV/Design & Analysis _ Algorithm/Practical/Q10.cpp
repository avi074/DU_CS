// Weighted Interval Schedueling
#include <iostream>
#include <algorithm>

using namespace std;

struct job
{
    uint start, finish, profit;

    job(const uint &s = 0, const uint &f = 0, const uint &p = 0)
    {
        start = s;
        finish = f;
        profit = p;
    }

    friend ostream &operator<<(ostream &out, const job &j)
    {
        out << '(' << j.start << ',' << j.finish << ',' << j.profit << ')' << endl;
        return out;
    }
};

bool cmp(job a, job b)
{
    return a.finish < b.finish;
}

int check_Overloop(const job *j, const uint &n)
{
    for (int i = n - 2; i >= 0; i--)
        if (j[n-1].start >= j[i].finish)
            return i;
    return -1;
}

uint wi_sch(const job *j, const uint &n)
{
    if (n == 0)
        return j[0].profit;

    else
    {
        int i = check_Overloop(j, n);
        int incl = j[n - 1].profit;
        if (i != -1)
            incl += wi_sch(j, i + 1);
        int excl = wi_sch(j, n - 1);
        return (incl > excl ? incl : excl);
    }
}

uint max_profit(job *j, const uint &n)
{
    sort(j, j + n, cmp);
    return wi_sch(j, n);
}

int main()
{
    job j[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(j) / sizeof(j[0]);
    cout << "The Optimal Profit is : " << max_profit(j, n) << endl;
    for (int i = 0; i < n; i++)
        cout << j[i] << endl;
}