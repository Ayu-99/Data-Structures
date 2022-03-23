class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        if(X>=Y):
            return X-Y
        
        if Y%2==0:
            
            return 1+self.brokenCalc(X,Y//2)
        
        return 1+self.brokenCalc(X,Y+1)
        
