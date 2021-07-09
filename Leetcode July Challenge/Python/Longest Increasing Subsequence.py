class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = []
        for num in nums:
            i = bisect.bisect_left(dp, num)
            if i == len(dp):
                dp.append(num)
            else:
                dp[i] = num
        return len(dp)
        
