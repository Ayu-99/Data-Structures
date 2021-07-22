def partitionDisjoint(self, A):
       maxleft = [A[0]]*len(A)
       for i in range(1,len(A)):
           maxleft[i] = max(maxleft[i-1], A[i])
           
       minright = [A[-1]]*len(A)
       for i in range(len(A)-2,-1,-1):
           minright[i] = min(minright[i+1], A[i]) 
       
       for i in range(len(A)-1):
           if maxleft[i] <= minright[i+1]:
               return i+1

def partitionDisjoint(self, A):
       minright = [A[-1]]*len(A)
       for i in range(len(A)-2,-1,-1):
           minright[i] = min(minright[i+1], A[i]) 

       maxleft = -float('inf')
       for i in range(len(A)-1):
           maxleft = max(maxleft, A[i])  
           if maxleft <= minright[i+1]:
               return i+1

def partitionDisjoint(self, A):
       disjoint = 0
       curmax = leftmax = A[0]
       for i,num in enumerate(A):
           curmax = max(curmax, num)
           if num < leftmax:
               leftmax = curmax
               disjoint = i
       return disjoint + 1  	
