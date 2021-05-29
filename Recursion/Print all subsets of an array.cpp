// Recursive Solution
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
class Solution {
public:
    vector<vector<int>> ans;
    
    void sub(vector<int> &nums, int i, vector<int> temp)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        sub(nums, i+1, temp); //exclude the current element
        temp.push_back(nums[i]); //small work
        sub(nums, i+1, temp); //include the current element
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;       
        sub(nums, 0, temp); 
        return ans;
    }
};
