#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}


void printGraph(vector<int> adj[], int V)
{
	for (int u = 0; u < V; ++u) {
		for (auto v : adj[u]) {
            cout<< u << "->" <<v<<endl;
        }
        cout<<"******** "<<endl;
	}
}

int main()
{
	int V = 5;
	vector<int> adj[V]; //adjacency list
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);
	printGraph(adj, V);
	return 0;
}
