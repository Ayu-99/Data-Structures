class Solution:
    def __init__(self):
        self.memo=[[[-1 for k in range(51)] for j in range(51)] for i in range(51)]
        self.mod = 1000000007
    
    def findPathsH(self,m, n, maxMove, i, j):
        if i>=m or i<0 or j>=n or j<0:
            return 1
        if maxMove<=0:
            return 0
        
        if self.memo[i][j][maxMove]!=-1:
            return self.memo[i][j][maxMove]
        
        res = 0
        res += self.findPathsH(m, n, maxMove-1, i+1, j)
        res += self.findPathsH(m, n, maxMove-1, i-1, j)
        res += self.findPathsH(m, n, maxMove-1, i, j+1)
        res += self.findPathsH(m, n, maxMove-1, i, j-1)
        
        
        self.memo[i][j][maxMove]= res % self.mod 
        return res % self.mod
        
        
    
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        
        return self.findPathsH(m, n, maxMove, startRow, startColumn) % self.mod
        
        
        
        
