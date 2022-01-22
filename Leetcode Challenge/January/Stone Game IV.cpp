class Solution {
public:
              
    int dp[100001];
    
    int helper(int n)
    {
        if(n<=0) return 0;
      if(dp[n]!=-1) return dp[n];    
        for(int i=1;i*i<=n;i++)
        {
            // if 2nd player return false then first will win; 
            if(helper(n-i*i)==0) return dp[n]=1;
        }
        
        return dp[n]=false;
        
    }
    bool winnerSquareGame(int n) {
        cout<<sizeof(dp);
        memset(dp,-1,sizeof(dp));
        return helper(n);
    }
};
