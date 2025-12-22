//brute-force approach

import java.util.HashMap;

class Solution {
    public static int findDuplicate(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int num : nums) {
            if (map.containsKey(num)) {
                return num;   // duplicate found
            }
            map.put(num, 1);
        }

        return -1; // ideally shouldn't happen if duplicate is guaranteed
    }
}


//optimized approach:
class Solution {
    public static boolean containsDuplicate(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int idx = Math.abs(nums[i]);
            if (nums[idx] < 0) return true;
            nums[idx] = -nums[idx];
        }
        return false;
    }
}

//check out my youtube channel where I solve DSA problems: https://www.youtube.com/@AyushiSharmaDSA/videos
