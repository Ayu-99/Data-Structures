class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
                    
        dp=[]
        for i in range(len(A)+1):
            x=[]
            for j in range(len(B)+1):
                x.append(0)
            dp.append(x)
        
          
        
        maxLength=0
        for i in range(1,len(A)+1):
            for j in range(1,len(B)+1):
                if A[i-1]==B[j-1]:
                    dp[i][j]=dp[i-1][j-1]+1
                    maxLength=max(dp[i][j], maxLength)
                    
        return maxLength
