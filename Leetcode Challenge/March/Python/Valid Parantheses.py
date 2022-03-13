class Solution:
    def isValid(self, s: str) -> bool:
        bracket = {"(":")", "[":"]", "{":"}"}
        open_par = set(["(", "[", "{"])
        stack=[]
        for i in s:
            if i in open_par:
                stack.append(i)
                
            elif stack and i == bracket[stack[-1]]:
                stack.pop()
                
            else:
                return False
            
            
        return stack == []  
