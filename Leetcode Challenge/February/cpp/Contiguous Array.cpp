class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp; 
        
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                nums[i] = -1;
            }
        }
        
        int sum=0,res=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            if(sum == 0){
                res = max(res, i+1);
            }
            
            if(mp.find(sum)!=mp.end()){ //sum is in map
                res=max(res,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return res;
    }
};
