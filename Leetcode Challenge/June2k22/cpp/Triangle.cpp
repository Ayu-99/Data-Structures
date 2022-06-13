class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> minlen(triangle.back());
        
        for (int i = n-2; i >= 0; i--) 
        {
            for (int j = 0; j <= i; j++) 
            {
                
                minlen[j] = min(minlen[j], minlen[j+1]) + triangle[i][j]; 
            }
        }
        return minlen[0];        
    }
};
