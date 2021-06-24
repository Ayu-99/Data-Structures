class Solution {
public:
    int memo[51][51][51];
    int mod = 1000000007;
    
    long findPathsH(int m, int n, int maxMove, int i, int j){
        
        if(i>=m || i<0 || j>=n || j<0){
            return 1;
        }
        if(maxMove <= 0){
            return 0;
        }
        
        if(memo[i][j][maxMove] != -1){
            return memo[i][j][maxMove];
        }
        
        long res = 0;
        res += findPathsH(m, n, maxMove - 1, i-1, j);
        res += findPathsH(m, n, maxMove - 1, i+1, j);
        res += findPathsH(m, n, maxMove - 1, i, j+1);
        res += findPathsH(m, n, maxMove - 1, i, j-1);
        return memo[i][j][maxMove] = res % mod;
        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(memo, -1, sizeof(memo));
        return findPathsH(m, n, maxMove, startRow, startColumn) % mod;
        
    }
};
