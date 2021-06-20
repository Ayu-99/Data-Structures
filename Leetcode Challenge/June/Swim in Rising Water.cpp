int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int low = 0, high = n*n-1;
        while(low < high){
            int mid = low + (high - low)/2;
            vector<vector<int>> visited(n, vector<int>(n,0));
            if(reachableOrNot(mid, grid, n, 0, 0, visited)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }

    int reachableOrNot(int T, vector<vector<int>>& grid, int N, int i, int j, vector<vector<int>> &visited) {
        
        

        if(i == N-1 && j == N-1){
            return true;
        }
        
        visited[i][j] = true;
        for(auto dir : dirs){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(new_i >= 0 && new_i < N && new_j >= 0 && new_j < N && !visited[new_i][new_j] && grid[i][j]<=T && grid[new_i][new_j] <= T){
                
                if(reachableOrNot(T, grid, N, new_i, new_j, visited)){
                    return true;
                }
                
            }
        }
        
        return false;
        
    }
};
