class Solution {
public:
    bool recursion(vector<int> &nums,int i,int sum,unordered_map<string,bool> &map)
    {   string s = to_string(i)+to_string(sum);
        if(map.find(s)!=map.end()) return map[s];
        if(sum<0) return false;
        if(sum==0) return true;
        if(i==nums.size()) return false;
        map[s] = recursion(nums,i+1,sum-nums[i],map) || recursion(nums,i+1,sum,map);
        return map[s];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
	    for(int i=0;i<n;i++)
        {
	        sum+=nums[i];
	    }
        if(sum%2!=0) return false;
        unordered_map<string,bool> map;
        return recursion(nums,0,sum/2,map);
    }
};
