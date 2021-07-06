from collections import defaultdict
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        
        d = defaultdict(int)
        for i in range(len(arr)):
            d[arr[i]] += 1
            
        
        l = list(d.values())
        l.sort(reverse = True)
        
        count = 0
        ans = 0
        index = 0
        size =  len(arr)
        while count*2 < size:
            ans += 1
            count += l[index]
            index += 1
        
        return ans
        
        
        
