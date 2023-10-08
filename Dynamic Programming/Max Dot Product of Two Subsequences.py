from collections import defaultdict
class Solution:
    
    def __init__(self):
        self.d = defaultdict(int)

    def maxDotProduct_helper(self, nums1, nums2, i, j):
        if i >= len(nums1) or j >= len(nums2):
            return 0
        
        if str(i) + " " + str(j) in self.d:
            return self.d[str(i) + " " + str(j)]
        
        ans = max(
            self.maxDotProduct_helper(nums1, nums2, i+1, j),
            nums1[i]*nums2[j] + self.maxDotProduct_helper(nums1, nums2, i+1, j+1),
            self.maxDotProduct_helper(nums1, nums2, i, j+1)
        )
        
        self.d[str(i) + " " + str(j)] = ans
        return ans
        
    
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        first_max = float('-inf')
        second_max = float('-inf')
        first_min = float('inf')
        second_min = float('inf')

        for num in nums1:
            first_max = max(first_max, num)
            first_min = min(first_min, num)
        for num in nums2:
            second_max = max(second_max, num)
            second_min = min(second_min, num)

        if (first_max < 0 and second_min > 0) or (first_min > 0 and second_max < 0):
            return max(first_max * second_min, first_min * second_max)
        
        return self.maxDotProduct_helper(nums1, nums2, 0, 0)
        
