# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param A : root node of tree
    # @param B : integer
    # @return the root node in the tree
    def getSuccessor(self, A, B):
        root = A
        ans = None
        while (root != None):
            if root.val == B:
                if root.right == None:
                    return ans
                else:
                    rootRight = root.right
                    while (rootRight.left != None):
                        rootRight = rootRight.left
                    return rootRight    
                
            else:
                if root.val > B:
                    ans = root #eligible candidate
                    root = root.left
                else:
                    root = root.right
        return ans            
