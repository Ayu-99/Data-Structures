/*
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3

*/

#include<bits/stdc++.h>
#define NMAX 55
using namespace std;

void initialize(bool **visited, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=false;
        }
    }
}

void dfs(char cake[NMAX][NMAX], int n, bool **visited, int i, int j, int &k){
    
    k++;
    visited[i][j]=true;
    
    if(j+1<n && cake[i][j+1]=='1' && !visited[i][j+1]){
        dfs(cake, n, visited, i, j+1, k);
    }
    
    if(i-1>=0 && cake[i-1][j]=='1' && !visited[i-1][j]){
        dfs(cake, n, visited, i-1, j, k);
    }
    
    if(i+1<n  && cake[i+1][j]=='1' && !visited[i+1][j]){
        dfs(cake, n, visited, i+1, j, k);
    }
   
    if(j-1>=0 && cake[i][j-1]=='1' && !visited[i][j-1]){
        dfs(cake, n, visited, i, j-1, k);
    }
    
    
    
    
}

int solve(int n,char cake[NMAX][NMAX]){
    
	// Write your code here
    
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[n];
        
    }
    
    initialize(visited, n);
    int max=0;
    for(int i=0;i<n;i++){
        
        for(int j=0;j<n;j++){
            int count=0;
 
            if(cake[i][j]=='1'){
                dfs(cake, n, visited, i, j, count);
                if(count>max){
                    max=count;
                }
            }
            initialize(visited, n);
        }
        
    }
    
    return max;
    
}
