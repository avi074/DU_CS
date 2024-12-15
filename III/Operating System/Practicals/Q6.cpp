#include <iostream>
#include <iomanip>

using namespace std;

void calc(const uint& n, int *at, int *bt, int *ct, int *tat, int* wt)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += bt[i];

        // Completion Time = cumulative sum of Burst time till the process starts
        ct[i] = sum;

        // Turn Around Time = Completion Time - Arrival Time
        tat[i] = ct[i] - at[i];

        // Waiting Time = Turn Around Time - Burst Time
        wt[i] = tat[i] - bt[i];
    }
}

void show(const uint& n, int *at, int *bt, int *ct, int *tat, int* wt)
{
    float sum = 0, sum1 = 0;
    cout << "\n Final Result ...";
    cout << "\n Process ID    Arrival Time    Burst Time    Completion Time    Turn Around Time    Waiting Time\n";
    for(int i = 0, j = 15; i < n; i++)
    {
        cout <<"\n" << setw(j/2) << i << setw(j) << at[i] << setw(j) << bt[i] 
             << setw(j) << ct[i] << setw(j + 5) << tat[i] << setw(j) << wt[i];
        sum += wt[i];
        sum1 += tat[i];
    }
    
    cout << "\n\n Average Waiting Time : " << sum / n << "ms \n Average Turn Around Time : " << sum1/n << "ms\n";
}

int main()
{
    uint n; 
    int **time = 0;

    cout << "\n\t\t FCFS Schedueling Algorithm \n\n";
    cout << " Enter the number of the processes : ";
    cin >> n;

    if(n > 1)
    {
        time = new int*[5];
        for(int i = 0; i < 5; i++)
            time[i] = new int[n];
        
        cout << "\n Process ID : Arrival Time  Burst Time\n";

        for(int i = 0; i < n; i++)
        {
            cout << "\n\t" << i << "   :\t ";
            cin >> time[0][i] >> time[1][i];
        }

        calc(n, time[0], time[1], time[2], time[3], time[4]);
        show(n, time[0], time[1], time[2], time[3], time[4]);

        for(int i = 0; i < 5; i++)
            delete[] time[i];
        delete[] time;
        time = 0;
    }
    else
        cout << "\n Enter atleast 2 processes !!!";

}