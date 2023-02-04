class Solution {
public:
    int helper[200][200]{}; 
    int maxPath, n, m;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxPath = 0, n = size(matrix), m = size(matrix[0]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                maxPath = max(maxPath, solve(matrix, i, j, -1));            
        return maxPath;
    }
    int solve(vector<vector<int>>& mat, int i, int j, int prev){
        if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] <= prev) return 0;
        if(helper[i][j]) return helper[i][j];
        return helper[i][j] = 1 + max({ solve(mat, i + 1, j, mat[i][j]),
                                    solve(mat, i - 1, j, mat[i][j]),
                                    solve(mat, i, j + 1, mat[i][j]),
                                    solve(mat, i, j - 1, mat[i][j]) });       
    }
};
