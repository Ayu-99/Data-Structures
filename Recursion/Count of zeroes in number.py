def countNumberOfZeros(n):
    if n==0: #base case
        return 0
    if n%10==0:
        return 1+countNumberOfZeros(n//10)
    else:
        return countNumberOfZeros(n//10)
n=708000
print(countNumberOfZeros(n))
