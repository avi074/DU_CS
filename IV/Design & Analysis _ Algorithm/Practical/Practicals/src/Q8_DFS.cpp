#include <iostream>

using namespace std;

#define v 5

int Graph[v][v] = {{1, 0, 0, 1, 0},
                   {0, 0, 1, 1, 1},
                   {0, 1, 0, 1, 0},
                   {1, 1, 1, 0, 0},
                   {0, 1, 0, 0, 0}};

bool visited[v] = {false};

// Depth First Search for Graphs
void DFS(int start)
{
    if (start < 0 || start > v-1)
        return;

    visited[start] = true;
    cout << '\t' << start ; 

    for(int i = 0; i < v; i++)
        if(Graph[start][i] && !visited[i])
            DFS(i);
}

int main(){
    cout << "\n\t\t   Practical 8\n\tDepth First Traversal for Graphs\n";

    cout << "\n\n Given Graph is :\n\n\t  Nodes   :   Edges\n";
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            if (Graph[i][j] && !(visited[j]))
            {
                visited[i] = true;
                cout << "\t " << i << " -- " << j << "   :\t" << Graph[i][j] << endl;
            }
    fill(visited, visited + v, false);
    cout << "\n Depth First Traversal for Graph at node 0 :\n";
    DFS(0);
}