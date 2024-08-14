class Solution(object):
    def smallestDistancePair(self, nums, k):
        nums.sort()
        n = len(nums)
        low, high = 0, nums[-1] - nums[0]

        def count_pairs(max_distance):
            count, j = 0, 0
            for i in range(n):
                while j < n and nums[j] - nums[i] <= max_distance:
                    j += 1
                count += j - i - 1
            return count

        while low < high:
            mid = (low + high) // 2
            if count_pairs(mid) < k:
                low = mid + 1
            else:
                high = mid

        return low
