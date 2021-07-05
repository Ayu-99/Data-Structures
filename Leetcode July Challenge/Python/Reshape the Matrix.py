

# Approach -1
class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])
        if rows*cols < r*c or rows*cols > r*c:
            return mat
        
        me = []
        for i in range(rows):
            for j in range(cols):
                me.append(mat[i][j])
        
        new_matrix = [[0 for j in range(c)] for i in range(r)]
        
        k = 0
        for i in range(r):
            for j in range(c):
                new_matrix[i][j] = me[k]
                k+=1
        
        return new_matrix
    
    
        
        
