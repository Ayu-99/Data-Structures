/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/
#include <iostream>
using namespace std;


bool printDFS(int **edges, int n, int sv, bool *visited, int v2){
    
    
    // cout<<sv<<endl;
	visited[sv]=true;
	if(edges[sv][v2]==1){
        return true;
    }
    
	for(int i=0;i<n;i++){
        
		if(edges[sv][i]==1){
			if(visited[i]){
				continue;
			}
			
			if(i==sv){
				continue;
			}
            if(printDFS(edges, n, i, visited, v2)){
                
                return true;
            }else{
                continue;
            }
		}
	}
    return false;
    
}

// bool DFS(int **edges, int n){
	
	
// }


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
		
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
			
	}
	
    bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
    int v1, v2;
    cin>>v1>>v2;
	int x=printDFS(edges, n, v1, visited, v2);
    if(x==1){
        cout<<"true";
    }else{
        cout<<"false";
    }
		
	delete []visited;
	
	// cout<<DFS(edges, n); //edges matrix, no. of vertices, starting vertex, visited nodes array
	
	
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	
	delete []edges;

  return 0;
}
