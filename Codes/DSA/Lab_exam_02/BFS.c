#include <stdio.h>

// Function to perform Breadth-First Search (BFS)
void bfs(int V, int adj[][V], int start)
{
    // Initialize visited array and queue for BFS
    int visited[V], queue[V], front = -1, rear = -1;

    // Mark all vertices as not visited
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    // Enqueue the start vertex and mark it as visited
    front++;
    rear++;
    queue[rear] = start;
    visited[start] = 1;

    // While there are vertices in the queue
    while (front <= rear)
    {
        // Dequeue a vertex and print it
        int s = queue[front];
        front++;
        printf("%d ", s);

        // Enqueue all adjacent vertices of the dequeued vertex and mark them as visited
        for (int i = 0; i < V; i++)
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

    // Ask for the number of vertices and edges
    printf("Enter the number of vertices (V) :");
    scanf("%d", &V);
    printf("Enter the number of Edges (E) : ");
    scanf("%d", &E);

    // Initialize adjacency matrix
    int adj[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adj[i][j] = 0;
        }
    }

    // Ask for the edges
    printf("Enter the Edge's :\n");

    for (int i = 0; i < E; i++)
    {
        int node1, node2;
        scanf("%d %d", &node1, &node2);

        adj[node1][node2] = 1;
        adj[node2][node1] = 1;
    }

    printf("Adjacency Matrix:\n");

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf(" %d  ", adj[i][j]);
        }
        printf("\n");
    }

    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    bfs(V, adj, start);
    return 0;
}