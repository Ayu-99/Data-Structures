class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count=0;
        int sum=0;
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum == k) count++;
            
            if(m.find(sum-k)!=m.end()){ //O(1)
                count=m[sum-k]+count; 
            }
            
            if(m.find(sum)!=m.end()){
                m[sum]++;
            }else{
                m[sum]=1;
            }
            
        }
        
        return count;
    }
};
