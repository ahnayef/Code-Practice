#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Node structure
struct Node
{
    int value;
    vector<Node *> children;
    Node(int val) : value(val) {}
};

// Heuristic function (can be user-defined)
int heuristic(Node *node)
{
    return node->value;
}

// Beam Search function
void beamSearch(Node *root, int beamWidth, int goal)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        vector<Node *> levelNodes;

        // Collect all nodes at current level
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            cout << "Visiting node with value: " << node->value << endl;
            if (node->value == goal)
            {
                cout << "Goal found: " << node->value << endl;
                return;
            }

            for (Node *child : node->children)
            {
                levelNodes.push_back(child);
            }
        }

        // Sort children based on heuristic and keep top-k (beam width)
        sort(levelNodes.begin(), levelNodes.end(), [](Node *a, Node *b)
             {
                 return heuristic(a) > heuristic(b); // higher value is better
             });

        // Add top-k to queue
        for (int i = 0; i < min(beamWidth, (int)levelNodes.size()); i++)
        {
            q.push(levelNodes[i]);
        }
    }

    cout << "Goal not found in the tree.\n";
}

int main()
{
    int beamWidth, goal;
    cout << "Enter beam width: ";
    cin >> beamWidth;
    cout << "Enter goal value to search: ";
    cin >> goal;

    // User input for creating the tree
    int rootValue;
    cout << "Enter the root node value: ";
    cin >> rootValue;
    
    Node* root = new Node(rootValue);
    
    // Create the tree using a breadth-first approach
    unordered_map<int, Node*> nodeMap;
    nodeMap[rootValue] = root;
    
    queue<int> parentQueue;
    parentQueue.push(rootValue);
    
    cout << "Tree Creation (enter -1 for no child)\n";
    
    while (!parentQueue.empty()) {
        int parentValue = parentQueue.front();
        parentQueue.pop();
        
        Node* parent = nodeMap[parentValue];
        
        cout << "Enter number of children for node " << parentValue << ": ";
        int numChildren;
        cin >> numChildren;
        
        for (int i = 0; i < numChildren; i++) {
            cout << "Enter value for child " << i+1 << " of node " << parentValue << ": ";
            int childValue;
            cin >> childValue;
            
            if (childValue != -1) {
                Node* child = new Node(childValue);
                parent->children.push_back(child);
                nodeMap[childValue] = child;
                parentQueue.push(childValue);
            }
        }
    }

    beamSearch(root, beamWidth, goal);

    // Memory cleanup
    for (auto& pair : nodeMap) {
        delete pair.second;
    }
    
    return 0;
}