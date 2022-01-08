class Solution {
public:
    int dy[3] = {0, -1, 1};
    int memo[71][71][71];
    
    int dfs(vector<vector<int>>& grid, int i, int c1, int c2, int m, int n) {

        if (i == m) return 0;
        if (c1 < 0 || c2 < 0 || c1 >= n || c2 >= n) return INT_MIN;
        if (memo[i][c1][c2] != -1) return memo[i][c1][c2];
        
        int maxAns = 0;
        
        for (int k=0; k<3; k++) {
            for (int r=0; r<3; r++) {
                maxAns = max(maxAns, dfs(grid, i + 1, c1 + dy[k], c2 + dy[r], m, n));
            }
        }
        
        maxAns += (c1 == c2) ? grid[i][c1] : grid[i][c1] + grid[i][c2];
        return memo[i][c1][c2] = maxAns;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        memset(memo, -1, sizeof memo);
        return dfs(grid, 0, 0, n-1, m, n);
    }
};
