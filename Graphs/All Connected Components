/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include<vector>



void printDFS(int **edges, int n, int sv, bool *visited,vector<int> &v){
	// cout<<sv<<endl;
	visited[sv]=true;
         v.push_back(sv);
	
	for(int i=0;i<n;i++){
        
		if(edges[sv][i]==1){
            
			if(visited[i]){
				continue;
			}
			
			if(i==sv){
				continue;
			}
			printDFS(edges, n, i, visited,v);
            
        
		}
	}
   
}

void DFS(int **edges, int n){
    vector<vector<int>> result;
	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
            
            vector<int> answer;
			printDFS(edges, n, i, visited,answer);
            result.push_back(answer);
		}
	}
    
    for(int i=0;i<result.size();i++){
        sort(result[i].begin(), result[i].end());
        for(int j=0;j<result[i].size();j++){
            cout<<result[i].at(j)<<" ";
        }
        cout<<endl;
    }
    
    
    
//     for(int i=0;i<result.size();i++){
//         sort(result[i].begin(),result[i].end());
//         for(int j=0;j<result[i].size();j++){
//             cout<<result[i].at(j)<<" ";
//         }
//         cout<<endl;
//     }
	delete []visited;
	
}


int main()
{
  // int V, E, tempX, tempY;
  // cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
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
	
	
	DFS(edges, n); //edges matrix, no. of vertices, starting vertex, visited nodes array
	
	
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	
	delete []edges;
	
    

  return 0;
}

