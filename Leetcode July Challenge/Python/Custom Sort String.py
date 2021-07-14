from collections import defaultdict
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        arr = [0] * 27
        print(arr)
        for i in range(len(order)):
            arr[ord(order[i]) - ord('a')] += 1
        
        s1 = "" 
        s2 = ""
        print(ord(order[0]) - ord('a'))
        for i in range(len(s)):
            if arr[ord(s[i]) - ord('a')] == 0:
                s2 += s[i]
            else:
                arr[ord(s[i]) - ord('a')]+=1
                
        for i in range(len(order)):
            while arr[ord(order[i]) - ord('a')] > 1:
                s1 += order[i]
                arr[ord(order[i]) - ord('a')] -= 1
        
        return s1+s2
                
        
        
            
            
        
