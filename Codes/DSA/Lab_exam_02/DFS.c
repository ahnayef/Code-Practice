#include<stdio.h>

// Function to perform Depth First Search (DFS). With recursion. You better know what that is.
void dfs(int V, int adj[][V],int visited[], int start)
{
    // Print the current node
    printf("%d ",start);
    
    // Mark the current node as visited
    visited[start] =1;
    
    // Loop through all vertices
    for(int i=0;i<V;i++)
    {
        // If the current node is connected to the i-th node and the i-th node is not visited
        if( adj[start][i]==1 && visited[i]==0)
        {
            // Perform DFS on the i-th node
            dfs(V,adj,visited,i);
        }
    }
}

int main()
{

    int V, E;
    
    // Ask for the number of vertices
    printf("Enter the number of vertices (V): ");
    scanf("%d", &V);
    
    // Ask for the number of edges
    printf("Enter the number of edges (E): ");
    scanf("%d", &E);
    
    // Initialize adjacency matrix with all zeros
    int adjMatrix[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    
    // Ask for the edges and fill the adjacency matrix
    printf("Enter the edge :\n");
    for (int i = 0; i < E; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);

        // It's an undirected graph. So, we mark both adjMatrix[node1][node2] and adjMatrix[node2][node1] as 1
        adjMatrix[node1][node2] = 1;
        adjMatrix[node2][node1] = 1;
    }



    // Ask for the starting node for DFS
    int start;
    printf("Enter the starting node: ");
    scanf("%d",&start);


    int visited[V];
    
    // Initialize all nodes as not visited
    for(int i =0;i<V;i++){
            visited[i] = 0;
    }



    printf("DFS traversal: ");
    
    // Perform DFS starting from the 'start' node
    dfs(V,adjMatrix,visited, start); 
    
    return 0;
}