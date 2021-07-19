# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
        
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == None or root == p or root == q:
            return root
        
        l, r = None, None
        if root.val > p.val and root.val > q.val:
            l = self.lowestCommonAncestor(root.left, p, q)
        
        elif  root.val < p.val and root.val < q.val:
            r = self.lowestCommonAncestor(root.right, p, q)
        
        else:
            l = self.lowestCommonAncestor(root.left, p, q)
            r = self.lowestCommonAncestor(root.right, p, q)
        
        if l and r:
            return root
        
        return l if l else r
