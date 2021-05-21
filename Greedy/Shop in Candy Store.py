def candyStore(self, candies,N,k):
        # code here
        maxa=0
        mina=0
        candies.sort()
        i=0
        j=N-1
        while i<=j:
            mina+=candies[i]
            j=j-k
            i+=1
        i=0
        j=N-1
        while i<=j:
            maxa+=candies[j]
            i=i+k
            j-=1
        return  [mina,maxa]
