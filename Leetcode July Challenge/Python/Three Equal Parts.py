class Solution:
    def threeEqualParts(self, arr: List[int]) -> List[int]:
        ans = [-1, -1]
        numOf1s = 0
        n = len(arr)
        for i in range(n):
            numOf1s += arr[i]
        
        if numOf1s % 3 != 0:
            return ans
        
        if numOf1s == 0:
            return [0, 2]
        
        numOf1sInEachPart = numOf1s // 3
        numOf1s = 0
        firstPart1, secondPart1, thirdPart1 = -1, -1, -1
        for i in range(n):
            if arr[i] == 1:
                numOf1s += 1
                if numOf1s == 1:
                    firstPart1 = i
                
                elif numOf1s == (numOf1sInEachPart + 1):
                    secondPart1 = i
                
                elif numOf1s == (2 * numOf1sInEachPart + 1):
                    thirdPart1 = i
        
        while thirdPart1 < n:
            if arr[thirdPart1] == arr[firstPart1] and arr[secondPart1] == arr[thirdPart1]:
                firstPart1 += 1
                secondPart1 += 1
                thirdPart1 += 1
            
            else:
                return ans
            
        
        return [firstPart1 - 1, secondPart1]
        
