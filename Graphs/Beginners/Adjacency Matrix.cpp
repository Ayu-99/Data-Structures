#include <bits/stdc++.h>
using namespace std;


void addEdge(int **adj, int u, int v)
{
    adj[u][v] = 1;
}


void printGraph(int **adj, int V)
{
	for (int u = 0; u < V; u++) {
		for(int v = 0; v < V; v++) {
            cout<<adj[u][v]<<" ";
        }
        cout<<endl;
	}
}

void init(int **adj, int V) {

    for(int i = 0; i < V; i++) {
        int *m = new int[V];
        adj[i] = m;
    }

    for(int u = 0; u < V; u++) {
        for(int v = 0; v < V; v++) {
            adj[u][v] = 0;
        }
    }

}

int main()
{
	int V = 5;
	int **adj = new int*[V]; //2-d array or matrix

    init(adj, V);
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
    addEdge(adj, 1, 0);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 3, 2);
	addEdge(adj, 3, 4);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);
	printGraph(adj, V);
	return 0;
}
