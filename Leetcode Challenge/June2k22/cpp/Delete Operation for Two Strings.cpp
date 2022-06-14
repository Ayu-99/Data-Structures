class Solution {
public:
    vector<vector<int>>dp;
    int minDistance(string& word1, string& word2) {
        dp.resize(size(word1) + 1, vector<int>(size(word2) + 1, 1000));
        return helper(word1, word2, 0, 0);
    }
    int helper(string &w1, string &w2, int i, int j) {
        if(i == size(w1) && j == size(w2)) return 0;
        if(i == size(w1) || j == size(w2)) return max(size(w1) - i, size(w2) - j);
        if(dp[i][j] != 1000) return dp[i][j];  
        if(w1[i] == w2[j]) return helper(w1, w2, i + 1, j + 1);
        return dp[i][j] = 1 + min(helper(w1, w2, i + 1, j), helper(w1, w2, i, j + 1));
    }
};
