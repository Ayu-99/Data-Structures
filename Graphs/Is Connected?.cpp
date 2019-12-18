/*
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
"true" or "false"
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/

#include <iostream>
using namespace std;




void printDFS(int **edges, int n, int sv, bool *visited){
	// cout<<sv<<endl;
	visited[sv]=true;
	
	for(int i=0;i<n;i++){
		if(edges[sv][i]==1){
			if(visited[i]){
				continue;
			}
			
			if(i==sv){
				continue;
			}
			printDFS(edges, n, i, visited);
		}
	}
}

int isConnected(int **edges, int n){
	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
    
	printDFS(edges, n, 0, visited);
		
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            return 0;
        }
    }
	
    return 1;
	delete []visited;



}










int main() {
    // int V, E;
    // cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */
    int n; //no. of vertices
	int e;// no. of edges
	
	cin>>n>>e;
	int **edges=new int*[n];
	for(int i=0;i<n;i++){
		edges[i]=new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}
	
	
	for(int i=0;i<e;i++){
		int f,s;
		// cout<<"Enter the first starting vertex and enter the ending vertex for an edge:"<<endl;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
			
	}
	
	int y=isConnected(edges, n); //edges matrix, no. of vertices, starting vertex, visited nodes array
	if(y==1){
        cout<<"true";
    }else{
        cout<<"false";
    }
	
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	
	delete []edges;

  return 0;
}
