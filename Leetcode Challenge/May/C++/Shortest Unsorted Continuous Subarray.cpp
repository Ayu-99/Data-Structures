class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while (low+1 < nums.size() && nums[low] <= nums[low+1]) low++;
        while (high-1 >= 0 && nums[high-1] <= nums[high]) high--;

        if (low == nums.size()-1) return 0;

        int wMin = INT_MAX, wMax = INT_MIN;
        for (int i = low; i <= high; i++) {
            wMin = min(wMin, nums[i]);
            wMax = max(wMax, nums[i]);
        }

        while (low-1 >= 0 && nums[low-1] > wMin) low--;
        while (high+1 <= nums.size()-1 && nums[high+1] < wMax) high++;

        return high - low + 1;
    }
};
