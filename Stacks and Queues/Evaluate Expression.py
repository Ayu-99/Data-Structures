×
class Solution:
    # @param A : list of strings
    # @return an integer
    def evalRPN(self, A):
        
        def result(a,b,op):
            if op=="+":
                return a+b
            elif op=='-':
                return b-a
            elif op=='*':
                return a*b
            else:
                return b//a
        
        
        stack=[]
        if len(A)==1:
            return int(A[0])
        for i in range(len(A)):
            
            if A[i] in ('/*+-'):
                a=stack.pop()
                b=stack.pop()
                
                stack.append(result(a,b,A[i]))
                
            
            elif str(abs(int(A[i]))).isdigit():
                stack.append(int(A[i]))
                
            
                
                
        return stack[-1]
