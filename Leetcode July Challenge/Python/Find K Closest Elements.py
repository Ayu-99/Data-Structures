class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        lo, hi = 0, len(arr)-k
        while lo<hi:
            mid = (lo + hi)//2
            if x-arr[mid]>arr[mid+k]-x:
                lo = mid + 1
            else:
                hi = mid
        return arr[lo:lo+k]
        
