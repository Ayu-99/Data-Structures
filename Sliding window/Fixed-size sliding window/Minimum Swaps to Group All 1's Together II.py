class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        k = 0
        n=len(nums)
        #total number of 1's in the array
        for i in range(n):
            if nums[i] == 1:
                k+=1
        low = 0
        high = 0
        sum = 0
        maxc=0
        while high < n+k: #circular array, high < n+k
            if high-low +1 < k: #to get the first window
                sum+=nums[high]
                high+=1
            else: # once you get the k size window, now you will just maintain and shift it
                sum+=nums[high%n]
                maxc=max(sum, maxc)
                sum-= nums[low%n] #shifting thw window
                high+=1
                low+=1
        
        #min swaps required
        return k-maxc
