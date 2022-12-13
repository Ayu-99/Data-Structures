// class Solution {
// public:
//     int minFallingPathSumHelper(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp){
//         if(r == 0 and c < matrix[0].size() and c >= 0) return matrix[r][c]; 
//         if(c >= matrix[0].size() or c < 0) return INT_MAX;
        
//         if(dp[r][c] != INT_MAX) return dp[r][c];
//         return dp[r][c] = matrix[r][c] + min(min(minFallingPathSumHelper(matrix, r-1, c+1, dp), minFallingPathSumHelper(matrix, r-1, c, dp)), minFallingPathSumHelper(matrix, r-1, c-1, dp));
        
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int rows = matrix.size(), cols = matrix[0].size();
//         vector<vector<int>> dp(rows+1, vector<int>(cols+1, INT_MAX));
//         int ans = INT_MAX;
//         for(int c=0; c < cols; c++){
//             ans = min(ans, minFallingPathSumHelper(matrix, rows-1, c, dp));
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int customMin(int a, int b, int c){
        return min(a,min(b,c));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int ans = INT_MAX;
        
        for(int r=1; r < rows; r++){
            for(int c=0; c < cols; c++){
                int leftD, middle, rightD;               
                if(c == 0){
                    rightD = matrix[r-1][c+1];
                    middle = matrix[r-1][c];
                    matrix[r][c] += min(rightD, middle);
                }else if(c == cols-1){
                    leftD = matrix[r-1][c-1];
                    middle = matrix[r-1][c];
                    matrix[r][c] += min(leftD, middle);
                }else{
                    leftD = matrix[r-1][c+1];
                    middle = matrix[r-1][c];
                    rightD = matrix[r-1][c-1];
                    matrix[r][c] += customMin(leftD, rightD, middle);
                } 
            }
        }
        for(int c=0; c < cols; c++){
            ans = min(ans, matrix[rows-1][c]);
        }
        return ans;
    }
};
