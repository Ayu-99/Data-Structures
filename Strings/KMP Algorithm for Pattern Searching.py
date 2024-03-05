pattern='balu'
text='this is balaji balu'


def lps():
    n=len(pattern)
    i=1
    j=0
    
    while i<n:
        if pattern[i]==pattern[j]:
            j+=1
            lp[i]=j
            i+=1
        else:
            if j!=0:
                j=lp[j-1]
            else:
                lp[i]=j
                i+=1
    print(lp)
    
def kmp():
    m=len(text)
    n=len(pattern)
    i=j=0
    
    while i<m:
        if text[i]==pattern[j]:
            i+=1
            j+=1
        if j==n:
            print('pattern found at the index:',i-j)
            j=lp[j-1]
        elif i<m and pattern[j]!=text[i]:
            if j!=0:
                j=lp[j-1]
            else:
                i+=1
lp=[0]*(len(pattern))
lps()
kmp()
                
