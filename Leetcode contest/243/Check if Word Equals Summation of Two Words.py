s1=""
s2=""
s3=""
for i in range(len(firstWord)):
    s1+=str(ord(firstWord[i])-97) 

for i in range(len(secondWord)):
    s2+= str(ord(secondWord[i])-97)
for i in range(len(targetWord)):
    s3+= str(ord(targetWord[i])-97)

n1=int(s1)
n2=int(s2)
n3=int(s3)
return n1+n2==n3  
