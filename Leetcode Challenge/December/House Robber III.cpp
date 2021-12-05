# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def __init__(self):
        self.d={}
        
    def rob_helper(self,root):
        if root==None:
            return [0,0] #[I, E]
        
        left=self.rob_helper(root.left)#[I, E] - I , E
        right=self.rob_helper(root.right) 
        
        
        res=[]
        res.append(root.val+left[1]+right[1]) #I
        res.append(max(left[0],left[1])+max(right[0],right[1])) #Eq
        
        return res
    
    def rob(self, root: TreeNode) -> int:
        y=self.rob_helper(root)
        return max(y[0],y[1])
        
        
        
