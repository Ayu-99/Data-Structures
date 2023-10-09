class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start=0
        end=len(nums)-1
        startIdx=-1
        
        while start<=end:
            
            mid=start+(end-start)//2
            if nums[mid]==target:
                startIdx=mid
                end=mid-1
            
            elif nums[mid]>target:
                end=mid-1
            else:
                start=mid+1
       
        start=0
        end=len(nums)-1
        endIdx=-1
        
        while start<=end:
            
            mid=start+(end-start)//2
            if nums[mid]==target:
                endIdx=mid
                start=mid+1
            
            elif nums[mid]>target:
                end=mid-1
            else:
                start=mid+1
        ans=[]
        ans.append(startIdx)
        ans.append(endIdx)
        return ans
       
            
