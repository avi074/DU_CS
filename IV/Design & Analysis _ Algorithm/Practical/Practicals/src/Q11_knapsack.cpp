#include <iostream>
#include <algorithm>

using namespace std;

#define max(a, b) a > b ? a : b;

struct Item
{
    int val, wt;

    // Constructor
    Item(int value, int weight)
    {
        this->val = value;
        this->wt = weight;
    }
};

int knapsack_dynamic(const uint &n, const uint &W, const Item arr[])
{
    int dp[W + 1] = {0};

    for (int i = 1; i <= n; i++)
        for (int w = W; w >= 0; w--)
            if (arr[i - 1].wt <= w)
            {
                dp[w] = max(dp[w],
                            dp[w - arr[i - 1].wt] + arr[i - 1].val);
            }
    return dp[W];
}

double knapsack_greedy(const uint &n, uint W, Item arr[])
{
    sort(arr, arr + n, [](const Item &a, const Item &b)
         { return (a.val * 1.0 / a.wt) > (b.val * 1.0 / b.wt); });

    double finalVal = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].wt <= W)
        {
            W -= arr[i].wt;
            finalVal += arr[i].val;
        }
        else
        {
            finalVal += arr[i].val * W * 1.0 / arr[i].wt;
            break;
        }
    }

    return finalVal;
}

int main()
{
    int W = 50; //    Weight of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\n\t\t   Practical 11 \n\t\tKnapSack Algorithm \n";

    cout << "\n Given Items are :\n\n S.N.\tValues\tWeight\n";
    for (int i = 0; i < n; i++)
        cout << "\n  " << i + 1 << "\t" << arr[i].val << '\t' << arr[i].wt;

    cout << "\n\n Dynamic Approach \n Obtained maximum value : " << knapsack_dynamic(n, W, arr) << endl;

    cout << "\n Greedy Approach \n Obtained maximum value : " << knapsack_greedy(n, W, arr) << endl;
}