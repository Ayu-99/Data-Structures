class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        int rows = accounts.size();
        int cols = accounts[0].size();
        for(int i = 0; i < rows; i++) {
            int wealth = 0;
            for(int j = 0; j < cols; j++) {
                wealth += accounts[i][j];
            }
            
            maxWealth = max(maxWealth, wealth);
        }
        return maxWealth;
    }
};

// T.C --
//      O(rows*cols)
// S.C      O(1)
