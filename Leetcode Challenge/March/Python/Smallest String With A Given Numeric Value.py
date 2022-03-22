class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        
        s=""
        for i in range(n):
            s+='a'
        
        k-=n
        l=['a']*n
        
        i=n-1
        while k>0:
            y=min(k,25)
            l[i]= chr(ord('a')+y)
            k-=y
            i-=1
            
        return ''.join(l)    
            
        
