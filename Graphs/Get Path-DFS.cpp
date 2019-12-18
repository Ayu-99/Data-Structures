/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
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
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/
#include <iostream>
using namespace std;
#include<vector>

void getPath(int **edges, int n, int v1, int v2, int *visited, vector<int> &v){
    // cout<<sv<<endl;
// 	visited[v1]=true;
//     s.push(v1);
    
    if(v1==v2){
        v.push_back(v2);
        return;
        
    }
    visited[v1]=true;
    
	
	for(int i=0;i<n;i++){
		if(edges[v1][i]==1){
            
			if(visited[i]){
				continue;
			}
			// s.push(i);
            // if(i==v2){
            //     s.push(v2);
            //     return s;
            // }
			if(i==v1){
				continue;
			}
            // v.push_back(i);
            getPath(edges, n, i, v2, visited, v);
			if(v.size()>0){
                // for(int i=s1.size()-1;i>0;i++){
                //     s1[i+1]=s1[i];
                
                v.push_back(v1);
                return;
                
                
                // s1[0]=i;
                // return s1;
            }
		}
	}
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
    
    int **edges=new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<E;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
        
    }
    
    int *visited=new int[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    
    vector<int> s1;
    int v1, v2;
    cin>>v1>>v2;
    getPath(edges, V, v1, v2, visited, s1);
    
    for(int i=0;i<s1.size();i++){
        cout<<s1[i]<<" ";

    }
    
  return 0;
}
