class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        
        deque<int> d{0};
        // cout<<d.front()<<endl;
        for (int i = 1; i < nums.size(); ++i) {
            if (d.front() + k < i)
                d.pop_front();        
            nums[i] += nums[d.front()];
            while (!d.empty() && nums[d.back()] <= nums[i])
                d.pop_back();
            d.push_back(i);
        }q
        return nums.back();
    }
};
