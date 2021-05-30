class Solution:
    def maxValue(self, n: str, x: int) -> str:
        res=""
        flag=False
        if(n[0]=='-'):
            res+='-'
            for i in range(1,len(n)):
                if int(n[i])>x:
                    res+=str(x)
                    res+= n[i:]
                    flag=True
                    break
                else:
                    res+=n[i]
            if not flag:
                res+=str(x)            
        else:
            for i in range(len(n)):
                if int(n[i])>=x:
                    res+=n[i]
                else:
                    res+=str(x)
                    res+= n[i:]
                    flag=True
                    break
            if not flag:
                res+=str(x)
        return res 
        
