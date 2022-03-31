class Solution {
public:
    int isPossible(vector<int>& nums, int mid) {
        int count=0,tempsum=0, n = nums.size();
            for(int i=0;i<n;i++){
                if(tempsum+nums[i]<=mid) tempsum+=nums[i];
                else count++,tempsum=nums[i];
            }
            count++; 
        return count;    
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l=0,r=0,n=nums.size();
        for(int i=0;i<n;i++) l=max(l,nums[i]), r+=nums[i];
        int mid=0,ans=0;
        while(l<=r){
            mid=(l+r)/2;
            int count = isPossible(nums,mid); //number of subrrays possible if max sum is mid
            if(count<=m) r=mid-1, ans=mid;
            else l=mid+1;
        }  
        return ans;
    }
};
