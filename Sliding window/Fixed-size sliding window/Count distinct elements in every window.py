from collections import defaultdict
class Solution:
    def countDistinct(self, arr, k):
        # Code here
        d = defaultdict(int)
        
        n = len(arr)
        low = 0
        high = 0
        res = []
        
        while high < n:
            if high - low + 1 < k:
                d[arr[high]] += 1
                high+=1
            else:
                d[arr[high]] += 1
                res.append(len(d))
                d[arr[low]] -= 1
                if d[arr[low]] == 0:
                    del d[arr[low]]
                low+=1
                high+=1
        return res         
