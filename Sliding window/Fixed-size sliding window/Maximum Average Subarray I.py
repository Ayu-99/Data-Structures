class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        start=0
        end=0
        sum=0
        maxAvg=float("-inf")

        #code format for fixed sliding window problems
        while end < len(nums):
            sum+=nums[end]
            #expanding the window to reach desired size of k
            if end-start+1 < k:
                end+=1
            else:
                avg=sum/k
                maxAvg=max(maxAvg,avg)
                #sliding window
                sum-=nums[start]
                start+=1
                end+=1

        return maxAvg
