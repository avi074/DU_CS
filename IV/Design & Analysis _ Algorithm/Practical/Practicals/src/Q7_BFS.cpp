#include <iostream>
#include <queue>

using namespace std;

#define v 5

int Graph[v][v] = {{1, 0, 0, 0, 1},
                   {0, 1, 1, 0, 1},
                   {0, 1, 0, 1, 0},
                   {0, 0, 1, 0, 0},
                   {1, 1, 0, 0, 1}};

bool visited[v] = {false};
queue<int> q;

// Breadth First Search for Graphs
void BFS(int start)
{
    if (start < 0 || start > v - 1)
        return;

    int begin;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        begin = q.front();
        q.pop();

        cout << '\t' << begin;

        for (int i = 0; i < v; i++)
            if (Graph[begin][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
    }
}

int main()
{
    cout << "\n\t\t   Practical 7\n\tBreadth First Traversal for Graphs\n";

    cout << "\n\n Given Graph is :\n\n\t Nodes    :   Edges\n";
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            if (Graph[i][j] && !(visited[j]))
            {
                visited[i] = true;
                cout << "\t " << i << " -- " << j << "   :\t" << Graph[i][j] << endl;
            }
    fill(visited, visited + v, false);
    cout << "\n Breadth First Traversal for Graph at node 1 :\n";
    BFS(1);
}