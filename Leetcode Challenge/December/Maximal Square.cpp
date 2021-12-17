class Solution {
public:
    
     //T.C - O(m*n) S.C - O(m*n)
    //  int maximalSquare(vector<vector<char>>& matrix) {
    //     if (matrix.empty()) {
    //         return 0;
    //     }
    //     int m = matrix.size(), n = matrix[0].size(), sz = 0;
    //     vector<vector<int>> dp(m, vector<int>(n, 0));
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (!i || !j || matrix[i][j] == '0') {
    //                 dp[i][j] = matrix[i][j] - '0';
    //             } else {
    //                 dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
    //             }
    //             sz = max(dp[i][j], sz);
    //         }
    //     }
    //     return sz * sz;
    // }
    
    //T.C - O(m*n) S.C - O(n)
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<int> pre(n, 0), cur(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    cur[j] = matrix[i][j] - '0';
                } else {
                    cur[j] = min(pre[j - 1], min(pre[j], cur[j - 1])) + 1;
                }
                sz = max(cur[j], sz);
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return sz * sz;
    }
};
