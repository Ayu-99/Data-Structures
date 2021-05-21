def maxProducts(price,k):
    l=[]
    n=len(price)
    for i in range(n):
        l.append([price[i],i+1])

    ans=0
    l.sort(key=lambda i:i[0])
    for i in range(n):
        ans += min(l[i][1],k//l[i][0])
        k -= l[i][0]*min(l[i][1],k//l[i][0])

    print(ans)

price=[10,7,19]
k=100
maxProducts(price,k)
