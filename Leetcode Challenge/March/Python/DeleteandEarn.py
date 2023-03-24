def deleteAndEarn(self, nums: List[int]) -> int:
        n = 10001
        values=[0]*n
        for num in nums:
            values[num] += num
        take = 0
        skip = 0
        for i in range(n):
            takei = skip + values[i]
            skipi = max(skip, take)
            take = takei
            skip = skipi
        
        return max(take, skip)
