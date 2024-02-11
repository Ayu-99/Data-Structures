# Definition for a  binary tree node
# class TreeNode:
#    def __init__(self, x):
#        self.val = x
#        self.left = None
#        self.right = None

class Solution:
    def inOrder(self, A, B, lis):
        if (A==None):
            return
        if (len(lis)>=B):
            return
        self.inOrder(A.left,B,lis)
        lis.append(A.val)
        self.inOrder(A.right,B,lis)
    # @param A : root node of tree
    # @param B : integer
    # @return an integer
    def kthsmallest(self, A, B):
        # lis=[]
        # self.inOrder(A,B,lis)
        # return lis[B-1]
        
        root = A
        stack = []
        while root or stack:
            if root:
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()
                B -= 1
                if B == 0:
                    return root.val
                root = root.right
        
        return None        
                
            
        
            
            
            
        
        
