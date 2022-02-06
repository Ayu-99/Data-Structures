class Solution {
    public int removeDuplicates(int[] nums) {
        int i=0;
        for(int k=0;k<nums.length;k++){
            
            if(i==0 || i==1 || nums[i-2]!=nums[k]){
                nums[i]=nums[k];
                i+=1;
            }
        }
        
        return i;
    }
}
