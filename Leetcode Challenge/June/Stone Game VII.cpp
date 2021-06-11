class Solution {
public:
    int dp[1000][1000][2];
    int stoneGame_helper(vector<int>& stones, int turn, int total_sum, int i, int j){
        if(i >= j){
            return 0;
        }
        if(dp[i][j][turn]!=-1)
        {
            return dp[i][j][turn];
        }
        if(turn == 1){ //alice turn
            
            int x=total_sum-stones[i];
            int res1 = stoneGame_helper(stones, 1-turn, x, i+1, j) + x;
            int y=total_sum-stones[j];
            int res2 = stoneGame_helper(stones, 1-turn, y,  i, j-1) + y;
            
            return dp[i][j][turn]=max(res1, res2);
        }
        else if(turn == 0){ //bob turn
            int x=total_sum-stones[i];
            int res1 = stoneGame_helper(stones, 1-turn, x,  i+1, j)-x;
            int y=total_sum-stones[j];
            int res2 = stoneGame_helper(stones, 1-turn, y, i,j-1)-y;        
            
            return dp[i][j][turn]=min(res1, res2);
        }
        return 0;
        
        
    }
    
    int stoneGameVII(vector<int>& stones) {
        
        memset(dp,-1,sizeof(dp));
        int turn=1, total_sum=0; //alice turn
        for(int i=0;i<stones.size();i++){
            total_sum += stones[i];
        }
        return stoneGame_helper(stones, turn, total_sum, 0, stones.size()-1);
    }
};
