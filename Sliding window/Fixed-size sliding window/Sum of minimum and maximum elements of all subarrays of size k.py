from sys import *
from collections import *
from math import *

def sumOfMaxAndMin(nums, n, k):
    # write your code here
    # return an integer denoting the answer
    maxi, mini = [], []
    low, high, sum = 0,0,0

    while high < n:
        if high - low + 1 < k:
            while len(maxi) > 0 and nums[maxi[-1]] < nums[high]:
                maxi.pop()
            while len(mini) > 0 and nums[mini[-1]] > nums[high]:
                mini.pop()
            maxi.append(high)
            mini.append(high)
            high+=1

        else:
            #step1
            while len(maxi) > 0 and nums[maxi[-1]] < nums[high]:
                maxi.pop()
            while len(mini) > 0 and nums[mini[-1]] > nums[high]:
                mini.pop()
            maxi.append(high)
            mini.append(high)    

            #step2
            if maxi[0] < low:
                maxi.pop(0)
            if mini[0] < low:
                mini.pop(0)  
            #step3
            sum += (nums[maxi[0]] + nums[mini[0]])
            
            #step4
            high+=1
            low+=1

    return sum    
