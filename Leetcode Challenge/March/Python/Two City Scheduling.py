class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        
        # costs.sort(key=lambda cost: cost[0] - cost[1])
        costs.sort(key=lambda cost: cost[0] - cost[1])
        print(costs)
        result=0
        
        for i in range(len(costs)//2):
            result+=costs[i][0]
        
        for j in range(len(costs)-1, (len(costs)//2)-1, -1):
    
            result+=costs[j][1]
        return result
