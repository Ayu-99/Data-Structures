class Solution:
    def minimumRecolors(self, nums: str, k: int) -> int:
        n = len(nums)
        low = 0
        high = 0
        sum = 0 #number of W's in the current window
        minc=float("inf")q
        while high < n:
            if high-low +1 < k: #to get the first window
                if nums[high] == 'W':
                    sum+=1
                high+=1
            else: # once you get the k size window, now you will just maintain and shift it
                if nums[high] == 'W':
                    sum+=1
                minc=min(sum, minc)
                if nums[low] == 'W':
                    sum-=1
                high+=1
                low+=1
        
        #min swaps required -- minimum count of W's present in any substring
        return minc
        
