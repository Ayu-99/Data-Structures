def minElements(arr , n):

	halfSum = 0
	for i in range(n):
		halfSum = halfSum + arr[i]
	
	halfSum = int(halfSum / 2)
	
	arr.sort(reverse = True)
	
	res = 0
	curr_sum = 0
	for i in range(n):
		
		curr_sum += arr[i]
		res += 1

		if curr_sum > halfSum:
			return res
	
	return res
	
arr = [3, 1, 7, 1]
n = len(arr)
print(minElements(arr, n) )
