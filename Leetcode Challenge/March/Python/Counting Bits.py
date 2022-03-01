class Solution:
    def countBits(self, num: int) -> List[int]:
        l=[]
        l.append(0)
        
        for i in range(1,num+1):
            if i%2!=0:
                
                l.append(l[i//2]+1)
            
                
            else:
                l.append(l[i//2])
                
        return l  
        
#         for i in range(num+1):
#             x=str(bin(i))
#             l.append(x.count('1'))
            
#         return l    
