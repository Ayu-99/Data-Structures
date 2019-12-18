/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 

*/

void  dfs(int **edges, int n, bool* &visited, int sv){
    // cout<<sv<<endl;
	visited[sv]=true;
	
	for(int i=1;i<=n;i++){
		if(edges[sv][i]==1){
			if(visited[i]){
				continue;
			}
			
			if(i==sv){
				continue;
			}
			dfs(edges, n, visited, i);
		}
	}
    
}


int countOfIslands(int **edges, int n){
    
    bool *visited=new bool[n];
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(edges, n, visited, i);
            count++;
        }
    }
    return count;
    
}


int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    
    int **edges=new int*[n];
    for(int i=1;i<=n;i++){
        edges[i]=new int[n];
        for(int j=1;j<=n;j++){
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<m;i++){
        edges[u[i]][v[i]]=1;
        edges[v[i]][u[i]]=1;
    }
    
    
    
    
    return countOfIslands(edges, n);
    
}
