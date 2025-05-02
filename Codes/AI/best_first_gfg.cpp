#include <bits/stdc++.h> // Include all standard C++ libraries
using namespace std;

// Function to perform Best First Search
vector<int> bestFirstSearch(vector<vector<int>> edges, 
        int src, int target, int n) {

    // Create the adjacency list to represent the graph
    vector<vector<vector<int>>> adj(n);
    for (int i = 0; i < edges.size(); i++) {
        // Add edge from source to destination with weight
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        // Add edge from destination to source (undirected graph)
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    // Create a visited array to keep track of visited nodes
    vector<bool> visited(n, false);

    // Create a min heap (priority queue) to store nodes based on cost
    priority_queue<vector<int>, vector<vector<int>>, 
            greater<vector<int>>> pq;

    // Push the source node into the min heap with cost 0
    pq.push({0, src});

    // Mark the source node as visited
    visited[src] = true;

    // Vector to store the path from source to target
    vector<int> path;

    // Loop until the min heap is empty
    while (!pq.empty()) {

        // Get the node with the lowest cost from the min heap
        int x = pq.top()[1];

        // Add the current node to the path
        path.push_back(x);

        // Remove the top element from the min heap
        pq.pop();

        // If the current node is the target node, stop searching
        if (x == target)
            break;

        // Loop through all adjacent nodes of the current node
        for (int i = 0; i < adj[x].size(); i++) {

            // If the adjacent node has not been visited
            if (!visited[adj[x][i][0]]) {

                // Mark the adjacent node as visited
                visited[adj[x][i][0]] = true;

                // Push the adjacent node into the min heap with its edge weight
                pq.push({adj[x][i][1], adj[x][i][0]});
            }
        }
    }

    // Return the path found from source to target
    return path;
}

int main() {
    int n = 14; // Number of nodes in the graph
    // Define the graph edges: {source, destination, weight}
    vector<vector<int>> edgeList = {
        {0, 1, 3}, {0, 2, 6}, {0, 3, 5},
        {1, 4, 9}, {1, 5, 8}, {2, 6, 12},
        {2, 7, 14}, {3, 8, 7}, {8, 9, 5},
        {8, 10, 6}, {9, 11, 1}, {9, 12, 10},
        {9, 13, 2}
    };

    int source = 0; // Starting node
    int target = 9; // Target node to reach

    // Call Best First Search to find the path
    vector<int> path = bestFirstSearch(edgeList, source, target, n);

    // Print the path from source to target
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    return 0;
}
