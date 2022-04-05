class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans=0;
        left=0;
        right=len(height)-1;
        while (left<=right):
            ans=max(min(height[left],height[right])*(right-left),ans)
            if height[left]<height[right]:
                left+=1
            else:
                right-=1
            
        return ans
