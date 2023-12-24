#include <stdio.h>

int main() {

    // Declare variables for vertices and edges
    int V, E;

    // Ask user for number of vertices
    printf("Enter the number of vertices (V): ");
    scanf("%d", &V);

    // Ask user for number of edges
    printf("Enter the number of edges (E): ");
    scanf("%d", &E);

    // Initialize adjacency matrix with size VxV
    int adjMatrix[V][V];

    // Fill the adjacency matrix with 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Ask user for edges connecting two vertices
    printf("Enter the edge :\n");
    for (int i = 0; i < E; i++) {
        int node1, node2;

        // Read edge from user
        scanf("%d %d", &node1, &node2);

        // Connect the two vertices
        adjMatrix[node1][node2] = 1;
        adjMatrix[node2][node1] = 1;
    }

    // Print the adjacency matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}