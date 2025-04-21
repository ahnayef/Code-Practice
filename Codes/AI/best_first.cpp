#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>
#include <algorithm>

using namespace std;

pair<bool, vector<int>> bestFirstSearch(int start, int target, vector<vector<int>> &graph,
                                        function<double(int, int)> heuristic)
{
    unordered_map<int, double> cost;
    unordered_map<int, int> parent;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> queue;

    cost[start] = 0;
    queue.push({heuristic(start, target), start});

    while (!queue.empty())
    {
        int current = queue.top().second;
        queue.pop();

        if (current == target)
        {
            vector<int> path;
            while (current != start)
            {
                path.push_back(current);
                current = parent[current];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return make_pair(true, path);
        }

        for (int neighbor : graph[current])
        {
            double newCost = cost[current] + 1;

            if (cost.find(neighbor) == cost.end() || newCost < cost[neighbor])
            {
                cost[neighbor] = newCost;
                parent[neighbor] = current;
                queue.push({heuristic(neighbor, target) + newCost, neighbor});
            }
        }
    }

    return make_pair(false, vector<int>());
}

int main()
{
    int numVertices, numEdges, startVertex, targetVertex;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (vertex1 vertex2):\n";
    for (int i = 0; i < numEdges; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }

    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "Enter the target vertex: ";
    cin >> targetVertex;

    function<double(int, int)> heuristic = [](int a, int b)
    {
        return 1;
    };

    pair<bool, vector<int>> result = bestFirstSearch(startVertex, targetVertex, graph, heuristic);

    if (result.first)
    {
        cout << "Target vertex found. Path: ";
        for (int vertex : result.second)
        {
            cout << vertex << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Target vertex not found." << endl;
    }

    return 0;
}