class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        
        def isValid(w1, w2):
            isPrefix = False
            isSuffix = False
            
            if len(w1) > len(w2):
                return False
              
            #checking for prefix    
            i = 0
            j = 0
            while (i < len(w1)):
                if w1[i] == w2[j]:
                    i+=1
                    j+=1
                    continue
                else:
                    break
            if i == len(w1):
                isPrefix = True
                
            
            #checking for suffix
            i = len(w1)-1
            j = len(w2)-1
            while (i >= 0):
                if w1[i] == w2[j]:
                    i-=1
                    j-=1
                    continue
                else:
                    break
                    
            if i < 0:
                isSuffix = True
                
            
            return isPrefix and isSuffix
        
        n = len(words)
        count = 0
        for i in range(n):
            for j in range(i+1, n):
                if isValid(words[i], words[j]):
                    count += 1
        return count            
                    
