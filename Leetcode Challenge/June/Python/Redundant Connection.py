from collections import defaultdict
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        p=[]
        for i in range(len(edges)+1):
            p.append(i)
            
        def findParent(src):
            if p[src]==src:
                return src
            
            return findParent(p[src])
        
        
        for u,v in edges:
            pu=findParent(u)
            pv=findParent(v)
            if pu==pv:
                return [u,v]
            
            p[pu]=pv
