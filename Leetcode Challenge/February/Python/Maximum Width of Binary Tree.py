class Solution(object):
    def widthOfBinaryTree(self, root):
        
        if root==None:
            return 0
        
        ans=1
        q=[[root,0]]
        
        while len(q)>0:
            size=len(q)
            start=q[0][1]
            end=q[-1][1]
            ans=max(ans,end-start+1)
            for i in range(size):
                current=q[0]
                idx=current[1]-start
                q.pop(0)
                if current[0].left!=None:
                    q.append([current[0].left,2*idx+1])
                if current[0].right!=None:
                    q.append([current[0].right,2*idx+2])
                    
            
        return ans  
