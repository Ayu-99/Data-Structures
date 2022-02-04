class Solution {
    public int findMaxLength(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 0) nums[i] = -1;
        }
        int sum = 0; 
        int max = 0; 
        Map<Integer, Integer> map = new HashMap<>();
        
        for(int i = 0; i < nums.length; i++){
            sum += nums[i]; 
            if(sum == 0) {
                max = Math.max(max, i+1);
            }
            if(map.containsKey(sum)){ 
                int last = map.get(sum); 
                max = Math.max(max, i - last); 
            }
            else{ 
                map.put(sum, i);
            }
        }
        return max;
    }
}
