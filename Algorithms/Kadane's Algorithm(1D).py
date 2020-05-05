#Maximum Subarray- Leetcode 53(DP)

"""
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.


"""
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        # this is kadane's theorem
        l=[0]*len(nums)
        
        l[0]=nums[0]
        maxv=nums[0]
        
        for i in range(1,len(nums)):
            
            l[i]=max(nums[i],nums[i]+l[i-1])
            maxv=max(maxv, l[i])
        
        return maxv
