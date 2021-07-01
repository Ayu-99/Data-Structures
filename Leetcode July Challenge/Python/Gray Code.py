class Solution:
    
    
    def grayCode(self, n: int) -> List[int]:
        
        def helper(n):
            
            if(n==1):
                return ["0","1"]
        
            x=helper(n-1)
            res=[]
            print(n, x)
            for i in range(len(x)):
                s=x[i]
                res.append("0"+s)
            print(n, res)    
            for i in range(len(x)-1,-1,-1):
                s=x[i]
                res.append("1"+s)
            print(n, res)
            return res
        
        res=helper(n)
        fres=[]
        for i in res:
            fres.append(int(i,2))
        return fres                        
            
