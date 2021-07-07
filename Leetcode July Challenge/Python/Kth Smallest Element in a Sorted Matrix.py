class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
       
        l = matrix[0][0]
        r = matrix[-1][-1]
        
        while l < r:
            m = l + (r - l) // 2
            if sum(bisect.bisect(row, m) for row in matrix) < k:   # calculate how many numbers are on the left of middle number
                l = m + 1
            else:
                r = m
        return l
