class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        visited=[0]*len(arr)
        def helper(arr, i):
            
            if i>=len(arr) or i<0:
                return False
            
            if arr[i]==0:
                return True
            
            if visited[i]:
                return False
                
            visited[i]=1
            
            x=helper(arr, i+arr[i])
            y=helper(arr, i-arr[i])
            
            return x or y
        
        
        return helper(arr, start)
