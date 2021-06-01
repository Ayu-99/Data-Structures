
class Solution {
public:
    bool isValid(int i,int j,int rows,int cols){
        if(i<0 || j<0 || i>=rows || j>=cols){
            return false;
        }else{
            return true;
        }
    }
    
    
    void dfs(int& area, vector<vector<int>>&grid, int i,int j,int rows, int cols){
        
        
        if(!isValid(i,j,rows,cols)){
            return;
        }
        
        if(grid[i][j]==0){
            return;
        }
        area++;
        grid[i][j]=0; 
        
        dfs(area, grid, i+1,j,rows,cols);
        dfs(area, grid, i-1,j,rows,cols);
        dfs(area, grid, i,j+1,rows,cols);
        dfs(area, grid, i,j-1,rows,cols);
         
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    int area=0;
                    dfs(area, grid, i,j,rows, cols);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};
