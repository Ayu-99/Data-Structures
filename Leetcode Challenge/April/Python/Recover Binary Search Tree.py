# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right



class Solution:
    def __init__(self):
        self.first = None
        self.second = None
        self.prev = None
    
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def markTree(curr):
            if (curr == None):
                return;
            markTree(curr.left);
            if (self.prev != None and self.prev.val > curr.val) :
                if (self.first == None):
                    self.first = self.prev;
                self.second = curr;
            
            self.prev = curr;
            markTree(curr.right);
        
        markTree(root);
        self.first.val, self.second.val = self.second.val, self.first.val
        
