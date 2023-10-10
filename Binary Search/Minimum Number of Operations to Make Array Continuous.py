class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        nums = sorted(set(nums))  # Make `nums` as unique numbers and sort `nums`.

        ans = n
        for i, start in enumerate(nums):
            end = start + n - 1  # We expect elements of continuous array must in range [start..end]
            idx = bisect_right(nums, end)  # Find right insert position
            uniqueLen = idx - i
            ans = min(ans, n - uniqueLen)
        return ans
#         n = len(nums)
#         ans = n
#         new_nums = sorted(set(nums))
#         j = 0
        
#         for i in range(len(new_nums)):
#             while j < len(new_nums) and new_nums[j] < new_nums[i] + n:
#                 j += 1
            
#             count = j - i
#             ans = min(ans, n - count)

#         return ans
        
