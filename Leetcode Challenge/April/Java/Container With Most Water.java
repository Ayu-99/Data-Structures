class Solution {
    public int maxArea(int[] height) {
        int ans=0;
        int left=0;
        int right=height.length-1;
        while (left<=right){
            ans=Math.max(Math.min(height[left],height[right])*(right-left),ans);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
}
