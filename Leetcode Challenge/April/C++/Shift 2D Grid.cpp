class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(); //rows
        int n = grid[0].size(); //cols
        vector<vector<int>> temp(m, vector<int>(n, 0));

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                int newVal = ((r*n + c) + k) % (m*n);
                int newr = newVal/n;
                int newc = newVal%n;
                temp[newr][newc] = grid[r][c];
                
            }
        }
        return temp;
    }
};
