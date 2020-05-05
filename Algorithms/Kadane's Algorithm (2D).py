#Leetcode - 304(DP)


"""
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
"""


class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        
        if matrix==[] or matrix[0]==[]:
            return None
        
        rows=len(matrix)
        cols=len(matrix[0])
        self.l=[]
        for i in range(0,rows+1):
            x=[]
            for j in range(0,cols+1):
                x.append(0)
            self.l.append(x)
        
        for i in range(1,len(self.l)):
            for j in range(1,len(self.l[0])):
                
                self.l[i][j]=matrix[i-1][j-1] + self.l[i-1][j]+self.l[i][j-1]-self.l[i-1][j-1]
        
        
                
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        
        row1+=1
        col1+=1
        row2+=1
        col2+=1
        
        return self.l[row2][col2]-self.l[row1-1][col2]-self.l[row2][col1-1]+self.l[row1-1][col1-1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
