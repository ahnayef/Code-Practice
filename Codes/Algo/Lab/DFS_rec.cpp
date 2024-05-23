#include <bits/stdc++.h>
using namespace std;
int adjMatrix[100][100];

void dfs(int V, int visited[], int start)
{
    cout << start << " ";
    visited[start] = 1;
    for (int i = 0; i < V; i++)
    {
        if (adjMatrix[start][i] == 1 && visited[i] == 0)
        {
            dfs(V, visited, i);
        }
    }
}
int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
    cout << "Enter the edge : ";
    for (int i = 0; i < E; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        adjMatrix[node1][node2] = 1;
        adjMatrix[node2][node1] = 1;
    }

    int start, visited[V];
    cin >> start;

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    dfs(V, visited, start);
}