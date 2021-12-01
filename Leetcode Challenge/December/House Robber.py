class Solution:
    
    
    def __init__(self):
        self.d={}
    
    
    def rob(self, nums: List[int]) -> int:
        
        def rob_helper(nums,n):
            
            if n==0:
                return nums[n]
            
            
            if n<0:
                return 0
            
            if n in self.d:
                return self.d[n]
            
            self.d[n]= max(nums[n]+
                           rob_helper(nums,n-2), rob_helper(nums,n-1))
            return self.d[n]
        
        
        return rob_helper(nums,len(nums)-1)
