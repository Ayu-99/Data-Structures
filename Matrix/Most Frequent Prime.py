from collections import defaultdict
import math
class Solution:
    def mostFrequentPrime(self, mat: List[List[int]]) -> int:
        
        def isPrime(x):
            if x == 0: return False
            if x == 1: return False
            for i in range(2, int(math.sqrt(x)) + 1):
                if x % i == 0: return False
            return True    
                
                
        dir = [[1,0], [-1,0], [0,1], [0,-1], [1,1], [1,-1], [-1,1], [-1,-1]]
        
        rows = len(mat)
        cols = len(mat[0])
        dict = defaultdict(int)
        for i in range(rows):
            for j in range(cols):
                cx = i
                cy = j
                val = mat[i][j]
                for d in dir:
                    cx += d[0]
                    cy += d[1]
                    while cx < rows and cx >= 0 and cy < cols and cy >= 0:
                        temp = val*10 + mat[cx][cy]
                        if temp > 10 and isPrime(temp):
                            dict[temp] += 1
                        val = temp
                        cx += d[0]
                        cy += d[1]
                        
                    val = mat[i][j]
                    cx = i
                    cy = j
                    
        ans = -1
        count= 0
        l = list(dict.keys())
        l.sort()
        l = l[::-1]
        for i in l:
            if dict[i] > count:
                count = dict[i]
                ans = i
        
        return ans
       
                
