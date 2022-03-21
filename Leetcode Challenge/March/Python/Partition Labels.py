class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        
        maxi=0
        initial=0
        result=[]
        for i in range(len(S)):
            if S.rindex(S[i])>maxi:
                maxi=S.rindex(S[i])
            
            if i==maxi:
                
                result.append(len(S[initial:maxi+1]))
                initial=i+1
                
        return (result)   
