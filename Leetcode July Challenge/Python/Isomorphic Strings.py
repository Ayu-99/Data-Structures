from collections import defaultdict
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        
        s_l = [0] * 128
        t_l = [0] * 128
        
        for i in range(len(s)):
            if s_l[ord(s[i]) - ord('a')] != t_l[ord(t[i]) - ord('a')]:
                return False
            
            s_l[ord(s[i]) - ord('a')] = i + 1
            t_l[ord(t[i]) - ord('a')] = i + 1
        return True
            
                

        
        
