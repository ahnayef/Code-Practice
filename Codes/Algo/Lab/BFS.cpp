#include<bits/stdc++.h>
using namespace std;
int adjMatrix[100][100];

void bfs(int no_vertices, int start){
	int visited[no_vertices];
	queue<int>q;

	for(int i=0;i<no_vertices;i++){
		visited[i] =0;
		}
	q.push(start);
	visited[start] = 1;

	while(!q.empty())
	{
		int s = q.front();
		cout<<s<<" ";
        q.pop();

		for(int i=0;i<no_vertices;i++)
		{
			if(adjMatrix[s][i]==1 && visited[i] == 0)
			{
			    q.push(i);

				visited[i] =1;
			}
		}
	}
}
int main()
{
	int V, E;
	cout<<"Enter the number of vertices: ";
    cin>>V;

    cout<<"Enter the number of edges: ";
    cin>>E;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    cout<<"Enter the edge : ";
    for (int i = 0; i < E; i++) {
        int node1, node2;
        cin>>node1>>node2;
        adjMatrix[node1][node2] = 1;
        adjMatrix[node2][node1] = 1;
    }

    int start;
    cout<<"Enter staring node:" ;
    cin>>start;
    bfs(V,start);
}