class Solution {
public:
    int dp[1001][1001] = {};
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = { 1 };
        for (int N = 1; N <= n; ++N)
            for (int K = 0; K <= k; ++K)
                for (int i = 0; i <= min(K, N - 1); ++i) 
                    dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % 1000000007;
        return dp[n][k];
}
    // int kInversePairs(int n, int k) {
    //     if (k <= 0)
    //         return k == 0;
    //     if (dp[n][k] == 0) {
    //         dp[n][k] = 1;
    //         for (auto i = 0; i < n; ++i) {
    //             dp[n][k] = (dp[n][k] + kInversePairs(n - 1, k - i)) % 1000000007;
    //         }
    //     }
    //     return dp[n][k] - 1;
    // }
};
