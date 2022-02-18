class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        
        stack = []
        for digit in num:
            while k > 0 and len(stack) > 0 and stack[-1] > digit:
                k -= 1
                stack.pop()  
            stack.append(digit)
            
        if k > 0:
            stack = stack[:-k]
            
        return "".join(stack).lstrip("0") or "0"
