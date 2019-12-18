/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

#include <iostream>
#include<climits>
using namespace std;


int findMinVertex(bool *visited, int *dist, int n){
    int minVertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minVertex == -1 || dist[minVertex]>dist[i])){
            minVertex=i;
        }
    }
    
    return minVertex;
}

void djikstra(int **edges, int n){
    
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    
    int *dist=new int[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    
    dist[0]=0;
    // visited[0]=true;
    
    for(int i=0;i<n;i++){
        //Min vertex
        
        int minVertex=findMinVertex(visited, dist, n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minVertex][j]!=0 && !visited[j]){
                int cdist=dist[minVertex]+edges[minVertex][j];
                if(cdist<dist[j]){
                    dist[j]=cdist;
                }
                
            }
        }
        
        
        
    }
    
    
    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
    
    
}

int main(){
    int n, e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    
    
    djikstra(edges, n);
    
    for(int i=0;i<n;i++){
        delete []edges[i];
    }
    
    delete []edges;
    
    return 0;
    
}
