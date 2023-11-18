#include <stdio.h>

void bfs(int no_vertices, int adj[][no_vertices], int start)
{
    int visited[no_vertices], queue[no_vertices], front = -1, rear = -1;

    for (int i = 0; i < no_vertices; i++)
    {
        visited[i] = 0;
    }

    front++;
    rear++;

    queue[rear] = start;
    visited[start] = 1;

    while (front <= rear)
    {
        int s = queue[front];
        front++;
        printf("%d\t", s);

        for (int i = 0; i < no_vertices; i++)
        {
            if (adj[s][i] == 1 && visited[i] == 0)
            {
                rear++;
                queue[rear] = i;
                visited[i] = 1;
            }
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

    


}