class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        
        start=0
        end=0
        countzeros=0
        maxv=0
        while end<len(A):
            if A[end]==0:
                countzeros+=1
            
            while countzeros>K:
                if A[start]==0:
                    countzeros-=1

                start+=1
               
            
            maxv=max(maxv,end-start+1)
            end+=1
            
        
        return maxv
