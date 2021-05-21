def maxMeeting(l, n):

	ans = []
	l.sort(key = lambda x: x[1])
	ans.append(l[0][2])
	time_limit = l[0][1] #e
	
	for i in range(1, n):
		if l[i][0] > time_limit:
			ans.append(l[i][2])
			time_limit = l[i][1]
			
	for i in ans:
		print(i , end = " ")
		
	print()


s = [ 1, 3, 0, 5, 8, 5 ]
f = [ 2, 4, 6, 7, 9, 9 ]
n = len(s)
l = []
for i in range(n):
	l.append([s[i], f[i], i+1])
	
maxMeeting(l, n)

