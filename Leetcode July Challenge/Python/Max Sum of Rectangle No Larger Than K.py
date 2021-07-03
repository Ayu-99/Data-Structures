import bisect
class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        ret = -math.inf
        m, n = len(matrix), len(matrix[0])
        # make sure rows > columns, otherwise we should rotate the matrix by zip() function
        if m < n:
            matrix = list(zip(*matrix))
        m, n = max(m, n), min(m, n)
        for le in range(n):
            pre_sum = [0] * m
            for ri in range(le, n): 
                for r in range(m):
                    pre_sum[r] += matrix[r][ri]
                arr = [0, math.inf] 
                cur_sum = 0
                for x in pre_sum:
                    cur_sum += x
                    idx = bisect.bisect_left(arr, cur_sum - k)
                    ret = max(ret, cur_sum - arr[idx])
                    if ret == k: return k
                    bisect.insort(arr, cur_sum) 
        return ret
