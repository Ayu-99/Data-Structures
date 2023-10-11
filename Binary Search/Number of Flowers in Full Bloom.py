class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        startTime = []
        endTime = []
        for i in flowers:
            startTime.append(i[0])
            
        for i in flowers:
            endTime.append(i[1])

        startTime.sort()
        endTime.sort()
        
        ans=[]
        for i in range(len(people)):
            upperBound = bisect_right(startTime, people[i])
            lowerBound = bisect_left(endTime, people[i])
            
            ans.append(upperBound - lowerBound)
        
        return ans
            
            
