def lastIndexOfNumberInArray(a,n,x):
    if n==0: # Base case
        return -1

    ans=lastIndexOfNumberInArray(a[1:],n-1,x) #recursive call
    # small work
    if ans!=-1:
        return ans+1
    else:
        if a[0]==x:
            return 0
        else:
            return -1


a=[9,8,10,8]  # 3
x=8
print(lastIndexOfNumberInArray(a,len(a),x))
