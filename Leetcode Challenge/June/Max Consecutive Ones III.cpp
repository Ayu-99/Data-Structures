class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int i = 0, j = 0, n = nums.size(), countZeros = 0, ans = INT_MIN;
        
        while(j < n){
            
            if(nums[j] == 0){
                countZeros++;
            }
            while(countZeros > k){
                
                if(nums[i] == 0){
                    
                    countZeros--;      
                }
                
                i++;
            }
            
            ans=max(ans, j-i + 1);
            
            j++;
            
        }
        
        return ans;
        
    }
};
