def maxMEX(arr, N, K):
    s = set()
    
    # Add 1 to N+1 into the set using while loop
    i = 1
    while i <= N + 1:
        s.add(i)
        i += 1
        
    mex = float("-inf")
    low = 0
    high = 0
    while high < N:
        if high - low + 1 < K:
          if arr[high] in s:
            s.remove(arr[high]) #not a potential candidate to be MEX
          high+=1
        else:
			  
          if arr[high] in s:
              s.remove(arr[high])

          firstElem = min(s)
          mex = max(mex, firstElem)
          s.add(arr[low])
          low += 1
          high += 1
	
    print(mex)

# Driver code
if __name__ == '__main__':
    arr = [3, 2, 1, 4]
    N = len(arr)
    K = 2
    maxMEX(arr, N, K)
