class Solution:
    def findPeakElement(self, arr: List[int]) -> int:
        n = len(arr)
        if n == 1:
            return 0
        low = 0
        high = n - 1
        while low <= high:
            mid = low + (high - low)//2
            
            if mid == 0:
                if arr[mid] > arr[mid + 1]:
                    return mid
                else:
                    low = mid + 1
                
                
            elif mid == n - 1:
                if arr[mid] > arr[mid - 1]:
                    return mid
                else:
                    high = mid-1
            
            
            else:
                if arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1]:
                    return mid
                
                elif arr[mid] < arr[mid + 1]:
                    low = mid + 1
                
                else:
                    high = mid - 1
                    
        return -1          
                    
        
