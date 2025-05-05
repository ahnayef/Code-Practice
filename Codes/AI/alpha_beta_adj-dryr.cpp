#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Alpha-Beta pruning with variable number of children per node
int alphaBeta(int nodeIndex, bool isMax, vector<int> &values, 
              vector<vector<int>> &children, int alpha, int beta)
{
    // Print function call details
    cout << "Call -> nodeIndex: " << nodeIndex
         << ", isMax: " << (isMax ? "Max" : "Min")
         << ", alpha: " << alpha
         << ", beta: " << beta << endl;

    // Base case: if we reached a leaf node (no children)
    if (children[nodeIndex].empty()) {
        cout << "  Leaf reached. Returning value[" << nodeIndex << "] = " << values[nodeIndex] << endl;
        return values[nodeIndex];
    }

    if (isMax) {
        int best = -1000; // Maximize the value

        // Process all children (variable number)
        for (int childIndex : children[nodeIndex]) {
            cout << "  Processing child " << childIndex << " of Max node " << nodeIndex << endl;
            int val = alphaBeta(childIndex, false, values, children, alpha, beta);
            best = max(best, val);
            alpha = max(alpha, best); // Update alpha

            // Pruning condition
            if (beta <= alpha) {
                cout << "  Pruning remaining children at Max node " << nodeIndex << ". (beta <= alpha)\n";
                break;
            }
        }
        
        cout << "  Returning from Max node " << nodeIndex << ": " << best << endl;
        return best;
    }
    else {
        int best = 1000; // Minimize the value

        // Process all children (variable number)
        for (int childIndex : children[nodeIndex]) {
            cout << "  Processing child " << childIndex << " of Min node " << nodeIndex << endl;
            int val = alphaBeta(childIndex, true, values, children, alpha, beta);
            best = min(best, val);
            beta = min(beta, best); // Update beta

            // Pruning condition
            if (beta <= alpha) {
                cout << "  Pruning remaining children at Min node " << nodeIndex << ". (beta <= alpha)\n";
                break;
            }
        }
        
        cout << "  Returning from Min node " << nodeIndex << ": " << best << endl;
        return best;
    }
}

int main()
{
    // Number of nodes in the tree (including internal nodes and leaves)
    int n = 10; // Nodes 0-9
    
    // Value for each node (for leaf nodes, this is the evaluation)
    vector<int> values(n, 0);
    values[5] = 3;   // Leaf
    values[6] = 5;   // Leaf
    values[7] = 2;   // Leaf
    values[8] = 9;   // Leaf
    values[9] = 1;   // Leaf
    
    // Adjacency list: children[i] contains the children of node i
    vector<vector<int>> children(n);
    
    // Example tree with variable children:
    // Node 0 (root) has 2 children
    children[0] = {1, 2};
    
    // Node 1 has 3 children
    children[1] = {3, 4, 5};
    
    // Node 2 has 1 child
    children[2] = {6};
    
    // Node 3 has 2 children
    children[3] = {7, 8};
    
    // Node 4 has 1 child
    children[4] = {9};
    
    // Nodes 5-9 are leaves (0 children)
    
    // Initial alpha and beta values
    int alpha = -1000, beta = 1000;

    // Call alphaBeta function starting from root node (index 0)
    int optimalValue = alphaBeta(0, true, values, children, alpha, beta);

    // Output the optimal value after Alpha-Beta Pruning
    cout << "Optimal value using Alpha-Beta Pruning: " << optimalValue << endl;

    return 0;
}