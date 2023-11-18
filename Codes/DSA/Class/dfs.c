#include <stdio.h>


void dfs(int V,int adj[][V],int visited[],int start){
    printf("%d\t",start);
    visited[start]=1;

    for (int i = 0; i < V; i++)
    {
        if (adj[start][i]==1 && visited[i]==0)
        {
            dfs(V,adj,visited,i);
        }
        
    }
    

}


int main()
{

    int V, E;
    printf("Enter the number of Vertices (V):");
    scanf("%d", &V); /// Declare the inputs
    printf("Enter the number of Edges (E):");
    scanf("%d", &E);

    int adjMatrix[V][V]; /// inputs of matriX
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adjMatrix[i][j] = 0; /// Initializing '0' for all adjaecent
        }
    }

    printf("Enter the Edge's:"); /// Taking Inputs OF Edge's
    for (int i = 0; i < E; i++)
    {
        int node1, node2;
        scanf("%d %d", &node1, &node2);

        adjMatrix[node1][node2] = 1;
        adjMatrix[node2][node1] = 1;
    }

    printf("Adjacency Matrix:\n"); /// Printing it Out ->>
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d  ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    int start, visited[V];
    scanf("%d", &start);
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    dfs(V, adjMatrix, visited, start);
}