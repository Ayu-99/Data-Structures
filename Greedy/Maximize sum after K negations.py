def sumList(a,n):
    return sum(a)

class Solution:
    def maximizeSum(self, a, n, k):
        a.sort()
        index=0
        for index in range(n):
            if k and a[index]<0:
                a[index]=-1*a[index]
                k-=1

                continue
            else:
                break

        #when all numbers are positive
        if index==0:
            index=1
        
        #when all numbers are negative
        if index==n:
            index-=1
        
        
        if k%2==0 or k==0:
            return sumList(a,n)
        
        #case-2
        if abs(a[index])>abs(a[index-1]):
            index-=1
            
        a[index]=-1*a[index]
        return sumList(a,n)
        
