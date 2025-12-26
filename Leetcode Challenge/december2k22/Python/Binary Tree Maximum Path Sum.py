# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.maxi=-99999

        def maxpath(root):

            if root is None:
                return 0


            lh=max(0,maxpath(root.left))
            rh=max(0,maxpath(root.right))

            self.maxi=max(self.maxi,root.val+lh+rh)




            

            return root.val+max(lh,rh)




        maxpath(root)
        return self.maxi
