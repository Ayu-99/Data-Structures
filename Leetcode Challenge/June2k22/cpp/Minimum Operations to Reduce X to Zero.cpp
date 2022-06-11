class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for (int i : nums) sum += i;
        int target = sum - x;
        int currSum = 0, maxLen=0;
        int i = 0; //starting index of subarray
        bool found = false;
        for (int j = 0; j < n; j++) {
            currSum += nums[j];
            
            //shrinking our window
            while (i <= j && currSum > target) {
                currSum -= nums[i];
                i += 1;
            }
            if (currSum == target) {
                found = true;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return found ? n - maxLen : -1;
    }
};
