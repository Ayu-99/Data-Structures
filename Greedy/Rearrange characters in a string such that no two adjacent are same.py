def getMaxCountChar(countArray):
    max=0
    ch=''
    for i in range(26):
        if countArray[i]>max:
            max=countArray[i]
            ch=chr(i+ord('a'))

    return ch

def rearrangeString(s):
    countArray=[0]*26
    n=len(s)
    for i in s:
        countArray[ord(i)-ord('a')]+=1

    c=getMaxCountChar(countArray)
    maxCount=countArray[ord(c)-ord('a')]

    if maxCount>(n+1)/2:
        return ""
    res=['']*n
    idx=0
    while maxCount:
        res[idx]=c
        idx+=2
        maxCount-=1

    countArray[ord(c)-ord('a')]=0
    for i in range(26):
        while countArray[i]>0:
            if idx>=n:
                idx=1
            res[idx]=chr(ord('a')+i)
            idx+=2
            countArray[i]-=1
    return ''.join(res)



s="bbbaaccdde"
# s="bbbaa"
res=rearrangeString(s)
if res=="":
    print("Not valid string possible")
else:
    print(res)

