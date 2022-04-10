class Solution:
    def calPoints(self, ops: List[str]) -> int:
        scores=[]
        size = 0;
        
        for i in ops:
            if(i == "+") :
                scores.append(scores[size-1] + scores[size-2]);
                size+=1
            elif(i == "D"):
                scores.append(2*scores[size - 1]);
                size+=1
            elif(i == "C"):
                size-=1
                scores.pop()
            else:
                size+=1;
                scores.append(int(i))
            
        
        
        sum = 0
        for i in scores :
            sum += i;
        
        
        return sum
