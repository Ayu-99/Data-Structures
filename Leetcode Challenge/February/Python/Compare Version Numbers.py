class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        
        l1=list(version1.split("."))
        l2=list(version2.split("."))
      
        for i in range(max(len(l1),len(l2))):
            v1=0
            v2=0
            if i<len(l1):
                v1=int(l1[i])
            if i<len(l2):
                v2=int(l2[i])
                
            if v1<v2:
                return -1
            elif v2<v1:
                return 1
            
                
        return 0        
        
