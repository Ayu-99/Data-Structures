class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        ans = float("inf")
        def enough(distance) -> bool:  # two pointers
            count, i, j = 0, 0, 0
            while i < n or j < n:
                while j < n and nums[j] - nums[i] <= distance:
                    j += 1
                count += j - i - 1
                i += 1  
            return count >= k

        nums.sort()
        n = len(nums)
        left, right = 0, nums[q-1] - nums[0]
        while left <= right:
            mid = left + (right - left) // 2
            if not enough(mid):
                left = mid + 1
            else:
                ans = min(ans, mid)
                right = mid-1
        return ans
