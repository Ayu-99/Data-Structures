# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def helper(self, root):
        if root == None:
            return 0
        
        if root.left == None and root.right == None:
            if root.val == 0:
                return 0
            else:
                return 1
        
        leftSubTreeOnes = self.helper(root.left)
        rightSubTreeOnes = self.helper(root.right)
        
        if leftSubTreeOnes == 0:
            root.left = None
            
        if rightSubTreeOnes == 0:
            root.right = None
        
        if root.val == 1:
            
            return leftSubTreeOnes + rightSubTreeOnes + 1
        
        else:
            return leftSubTreeOnes + rightSubTreeOnes
        
    
    def pruneTree(self, root: TreeNode) -> TreeNode:
        if self.helper(root) == 0:
            return None
        else:
            return root
        
