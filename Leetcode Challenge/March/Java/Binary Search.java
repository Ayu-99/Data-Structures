class Solution {
    public int search(int[] nums, int target) {
         int n = nums.length;
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            // int mid =(low+high)/2; //middle index
            if(nums[mid] == target) return mid;
            
            else if(nums[mid] < target) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
            
        }
        return -1;
    }
}
