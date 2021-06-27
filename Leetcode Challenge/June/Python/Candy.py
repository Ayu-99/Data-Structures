class Solution:
    def candy(self, ratings: List[int]) -> int:
        
        candies = [1]*len(ratings)
        if len(ratings) == 1:
            return 1
        
        for i in range(1,len(ratings)):
            if ratings[i]>ratings[i-1] and candies[i] <=candies[i-1]:
                candies[i]=candies[i-1]+1
            
            
        for i in range(len(ratings)-2,-1,-1):
            if ratings[i]>ratings[i+1] and candies[i] <=candies[i+1]:
                candies[i]=candies[i+1]+1
        
        return sum(candies)
        
