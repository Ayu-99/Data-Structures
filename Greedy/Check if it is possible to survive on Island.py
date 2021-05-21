# Python3 program to find the minimum days on
# which you need to buy food from the shop so
# that you can survive the next S days
def survival(S, N, M):

# If we can not buy at least a week
# supply of food during the first week
# OR We can not buy a day supply of food
# on the first day then we can't survive.
	if (((N * 6) < (M * 7) and S > 6) or M > N):
		print("No")
	else:
		
	# If we can survive then we can
	# buy ceil(A / N) times where A is
	# total units of food required.
		days = (M * S) / N
		
		if (((M * S) % N) != 0):
			days += 1
		print("Yes "),
		print(days)

# Driver code
S = 10; N = 16; M = 2
survival(S, N, M)

