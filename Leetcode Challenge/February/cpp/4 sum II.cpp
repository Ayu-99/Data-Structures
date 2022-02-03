class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> mp;
        
        for(int k : nums3){
            for(int l : nums4){       
                mp[k + l]++;
            }
        }
        
        int count = 0;
        for(int i : nums1) {
            for(int j : nums2){
                    count += mp[-(i + j)];
                }
            }
        return count;
    }
};
