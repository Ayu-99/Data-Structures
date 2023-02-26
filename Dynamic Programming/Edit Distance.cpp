class Solution {
public:
    int minDistanceHelper(string& word1, string& word2, vector<vector<int>>& dp, int i, int j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
        
    //base case
    if (i == 0) {
        dp[i][j] = j;
        return j;
    }
        
    //base cases
    if (j == 0) {
        dp[i][j] = i;
        return i;
    }
    if (word1[i - 1] == word2[j - 1]) {
        dp[i][j] = minDistanceHelper(word1, word2, dp, i - 1, j - 1);
    } 
    else {
            int insertOp = minDistanceHelper(word1, word2, dp, i, j-1); 
            int deleteOp = minDistanceHelper(word1, word2, dp, i-1, j); 
            int replaceOp = minDistanceHelper(word1, word2, dp, i-1, j-1);
            dp[i][j] = 1+ min({insertOp, deleteOp, replaceOp});
    }
    return dp[i][j];
}
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return minDistanceHelper(word1, word2, dp, m, n);
    }
};
