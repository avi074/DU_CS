
#include<iostream>
using namespace std;
int main()
{
    int v;
    int sum=0, flag=0;
    system("cls");
    cout<<"\n Enter the number of vertices of graph :";
    cin>>v;
    int graph[v-1][v-1];
    cout<<"\n Enter values in adjacency matrix of Graph \n"<<endl;
    for (int i = 0; i < v; i++)
    {
        char r= 97+i;
        for (int j = 0; j < v; j++)
        {
            char c=97+j;
            cout<<"Enter the value of ("<<r<<","<<c<< ") position : ";
            cin>>graph[i][j];
        }
        cout << "\n";
    }
    // Checking here graph is complete graph or not
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i==j && graph[i][j]!=0)
            {
                flag=(-1);
                break;
            }
            else if (i!=j && graph[i][j]==0)
            {
                flag=(-1);
                break;
            }
        }
        
    }
    if (flag==(-1))
    {
        cout<<"The graph is not a complete graph!!! \n";
    }
    else
    cout<<"The graph is complete graph......\n";

cin.get();
cin.ignore();
}
