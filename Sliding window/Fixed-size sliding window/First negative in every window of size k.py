#User function Template for python3

class Solution:
    def firstNegInt(self, arr, k): 
         # code here 
        # n = len(arr)
        # low = 0
        # high = 0
        # d = []
        # res = []
        
        # while high < n:
        #     if high - low + 1 < k:
        #         if arr[high] < 0:
        #             d.append(high)
        #         high += 1
        #     else:
        #         if arr[high] < 0:
        #             d.append(high)
        #         if len(d) != 0:
        #             res.append(arr[d[0]])
        #         else:
        #             res.append(0)
                
        #         while len(d) > 0:
        #             if d[0] < low+1:
        #                 d.pop(0)
        #             else:
        #                 break
        #         low+=1
        #         high+=1
        
        # return res 
        n = len(arr)
        low = 0
        high = 0
        fst_neg_idx = 0  # pointer to track the first negative number
        res = []
        while high < n:
        # Expand window until size reaches k
            if high - low + 1 < k:
                high += 1
            else:
            # Remove out-of-window or positive elements
                while fst_neg_idx < low or (fst_neg_idx <= high and arr[fst_neg_idx] >= 0):
                    fst_neg_idx += 1
    
                # Add result
                if fst_neg_idx >= low and fst_neg_idx <= high and arr[fst_neg_idx] < 0:
                    res.append(arr[fst_neg_idx])
                else:
                    res.append(0)

                # Slide the window
                low += 1
                high += 1

        return res
