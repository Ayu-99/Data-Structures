def maxSum(a,n):
    sum=0
    a.sort()
    l=[]
    counter=0
    k=0
    i=0
    j=n-1
    while k<n:
        if counter%2==0:
            l.append(a[i])
            i+=1
        else:
            l.append(a[j])
            j-=1
        counter+=1
        k+=1
    maxSum=0
    for i in range(0,n-1):
        maxSum+=abs(l[i+1]-l[i])

    maxSum+=(l[n-1]-l[0])
    print(maxSum)

n=4
a=[1,2,4,8]
maxSum(a,n)
