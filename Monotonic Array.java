class Solution {
    public boolean isMonotonic(int[] nums) {
        boolean inc = true, dec = true;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1]) {
                inc = false;
            }
            if (nums[i] > nums[i - 1]) {
                dec = false;
            }
        }

        return inc || dec;
    }
}
