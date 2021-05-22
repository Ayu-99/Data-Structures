def findMinDiff(self, A,N,M):
        i=0
        j=M-1
        d=float("inf")
        A.sort()
        while j<N:
            d=min(d,A[j]-A[i])
            j+=1
            i+=1
        
        return d 
