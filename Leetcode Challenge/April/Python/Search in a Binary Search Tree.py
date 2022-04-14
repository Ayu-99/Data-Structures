# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def helper(self,root,val):
        if root==None:
            return None
        if root.val==val:
            return root
        if root.val>val:
            return self.helper(root.left,val)
        
        return self.helper(root.right,val)
    
    
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if root==None:
            return None
        
        return self.helper(root,val)
        
        
