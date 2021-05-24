def firstIndexOfNumberInArray(a,n,x):
    if n==0: # Base case
        return -1

    elif a[0]==x: # small work
        return 0
    else:
        ans=firstIndexOfNumberInArray(a[1:],n-1,x) #recursive call
        if ans==-1: #small work
            return -1
        else:
            return ans+1


a=[9,8,10,8]  # 1
x=8
print(firstIndexOfNumberInArray(a,len(a),x))
