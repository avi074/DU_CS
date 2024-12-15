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

bool cmp(const job &a, const job &b)
{
    return a.finish < b.finish;
}

int check_Overloop(const job *j, const uint &n)
{
    for (int i = n - 2; i > -1; i--)
        if (j[n - 1].start >= j[i].finish)
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
    cout << "\n\nSorted jobs according to respective finish time are :\n\n"
         << "S.N.\t   Start-time\t   Finish-time\t\tProfit\n";
    for (int i = 0; i < n; i++)
        cout << "\n " << i + 1 << "\t\t" << j[i].start << "\t\t" << j[i].finish << "\t\t" << j[i].profit;
    return wi_sch(j, n);
}

int main()
{
    job j[] = {{3, 10, 20}, {1, 24, 50}, {6, 19, 100}, {2, 100, 20}};
    int n = sizeof(j) / sizeof(j[0]);

    cout << "\n\t\t Practical 10 \n\t Weighted Interval Schedueling \n";

    cout << "\nGiven jobs are :\n\nS.N.\t   Start-time\t   Finish-time\t\tProfit\n";
    for (int i = 0; i < n; i++)
        cout << "\n " << i + 1 << "\t\t" << j[i].start << "\t\t" << j[i].finish << "\t\t" << j[i].profit;

    int mx = max_profit(j, n);
    cout << "\n\nThe Maximum Optimal Profit is : " << mx << endl;
}