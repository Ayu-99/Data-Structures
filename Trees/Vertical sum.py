class Solution:
    
    def __init__(self):
        self.m = defaultdict(int)
        
    def verticalSumHelper(self, root, hd): 
        if root == None:
            return
        
        self.m[hd] += root.data
        self.verticalSumHelper(root.left, hd-1)
        self.verticalSumHelper(root.right, hd+1)
        
    def verticalSum(self, root):
        #:param root: root of the given tree.
        self.verticalSumHelper(root, 0)
        ans = []
        keys = list(self.m.keys())
        keys.sort()
        for i in keys:
            ans.append(self.m[i])
        
        return ans  
