class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        e=0
        cnt=0
        
        
        for i in range(len(nums)):
            if cnt==0:
                e=nums[i]
            
            if e==nums[i]:
                cnt+=1
            else:
                cnt-=1
        
        return e
