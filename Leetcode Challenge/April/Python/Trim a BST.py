# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def trimBST(self, root: TreeNode, L: int, R: int) -> TreeNode:
        
        if root==None:
            return None
        
        if root.val==L:
            root.left=None
            root.right=self.trimBST(root.right, L, R)
            return root
        
        
        if root.val==R:
            root.right=None
            root.left=self.trimBST(root.left, L, R)
            return root
        
        
        if root.val>R and root.val>L:
            return self.trimBST(root.left, L, R)
        
        if root.val<L and root.val<R:
            return self.trimBST(root.right, L, R)
       
    
        root.left=self.trimBST(root.left, L, R)
        root.right=self.trimBST(root.right, L, R)
        
        return root
