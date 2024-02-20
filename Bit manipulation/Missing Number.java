class Solution {
    public int missingNumber(int[] nums) {
        int ans = 0;
        int n = nums.length;
        for(int i = 1; i <= n; i++) {
            ans ^= i;
        }
        
        for(int i = 0; i < n; i++) {
            ans ^= nums[i];
        }
        
        return ans;
    }
}
