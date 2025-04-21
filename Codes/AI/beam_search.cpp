#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

    // Creating a simple tree manually
    Node *root = new Node(1);
    root->children = {new Node(4), new Node(3), new Node(2)};

    root->children[0]->children = {new Node(10), new Node(5)};
    root->children[1]->children = {new Node(8), new Node(6)};
    root->children[2]->children = {new Node(7), new Node(9)};

    beamSearch(root, beamWidth, goal);

    // Memory cleanup (optional in this small example)
    return 0;
}
