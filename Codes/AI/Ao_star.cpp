#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node
{
    int data; 
    bool mark = false; // true explored 
    bool solved = false;
    vector<vector<Node *>> children; // Each OR node has a list of AND nodes
};

int edge_cost = 0; /// moving along the edge between two nods

/* for insert*/

///Builds the AND-OR tree recursively
///Gets its initial heuristic value
///Gets number of OR options
///For each OR option, gets number of AND nodes
///Recursively builds each AND node

void insert(Node *root){
    cout << "Enter data for node: ";
    cin >> root->data;

    int or_count;
    cout << "Enter number of OR choices for node " << root->data << ": ";
    cin >> or_count;

    for (int i = 0; i < or_count; ++i)
    {
        int and_count;
        cout << "Enter number of AND nodes for OR choice " << i + 1 << ": ";
        cin >> and_count;

        vector<Node *> and_nodes;
        for (int j = 0; j < and_count; ++j)
        {
            Node *child = new Node();
            insert(child);
            and_nodes.push_back(child);
        }
        root->children.push_back(and_nodes);
    }
}


/// Follows marked nodes to find the current exploration frontier
/// Chooses the least-cost OR option at each step

void aostar(Node *root)
{
    if (!root)
        return;

    while (!root->solved) /// mark root->solveed
    {
        Node *current = root;
        vector<Node *> path;

        // Traverse marked nodes
        while (current->mark && !current->children.empty())
        {
            path.push_back(current); ///traversal paths
            int min_cost = INT_MAX; /// + infinite 
            Node *next = nullptr;

            for (auto &or_nodes : current->children)
            {
                int cost = 0;
                for (auto node : or_nodes)
                    cost += node->data + edge_cost; /// to determmine the cost of  the current node 

                if (cost < min_cost)
                {
                    min_cost = cost;
                    for (auto node : or_nodes)
                        if (!node->mark)
                            next = node;
                }
            }

            current = next;
            if (!current)
                break;
        }

        if (!current)
            break;

        cout << "Exploring node: " << current->data << endl;

        // Update cost
        // if (current->children.empty())
        // {
        //     current->mark = true;
        // }
        // else
        // {
        //     int min_cost = INT_MAX;
        //     for (auto &or_nodes : current->children)
        //     {
        //         int cost = 0;
        //         for (auto node : or_nodes)
        //             cost += node->data + edge_cost;
        //         min_cost = min(min_cost, cost);
        //     }
        //     current->data = min_cost;
        //     current->mark = true;
        // }


        // Update cost
        if (current->children.empty())
        {
            current->mark = true; // Terminal node , leaf mode 
        }

        else
        {
            int min_cost = INT_MAX;
            for (auto &or_nodes : current->children)
            {
                // For AND nodes, take MAX cost
                int and_cost = 0;
                for (auto node : or_nodes)
                {
                    and_cost = max(and_cost, node->data + edge_cost);
                }
                min_cost = min(min_cost, and_cost);
            }
            current->data = min_cost;
            current->mark = true;
        }

        // Update all nodes in path
        for (auto it = path.rbegin(); it != path.rend(); ++it)
        {
            Node *node = *it;
            int min_cost = INT_MAX;
            for (auto &or_nodes : node->children)
            {
                int cost = 0;
                for (auto child : or_nodes)
                    cost += child->data + edge_cost;
                min_cost = min(min_cost, cost);
            }
            node->data = min_cost;

            // If best path's children are all marked, mark this node
            bool all_marked = true;
            for (auto child : node->children[0])
                all_marked &= child->mark;
            node->solved = all_marked;
         }

        // If root is solved, break
        if (root->solved)
            break;
    }
}

void print(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    for (auto &or_nodes : root->children)
        for (auto node : or_nodes)
            print(node);
}

int main()
{
    Node *root = new Node();
    insert(root);

    cout << "\nEnter the edge cost: ";
    cin >> edge_cost;

    cout << "\nTree structure (Preorder traversal): ";
    print(root);
    cout << "\n\nStarting AO* Algorithm...\n";

    aostar(root);

    cout << "\nMinimum cost from root: " << root->data << endl;
    return 0;
} 