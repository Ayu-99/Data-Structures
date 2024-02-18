from collections import defaultdict
class TrieNode:
    def __init__(self, c):
        self.char = c
        self.children = [None] * 10
        self.isEnd = False
        
class Solution:
    
    def __init__(self):
        self.root = TrieNode('100')
        
    def insert(self, word):
        ptr = self.root
        for i in range(len(word)):
            idx = ord(word[i]) - ord('0')
            if ptr.children[idx] == None:
                ptr.children[idx] = TrieNode(word[i])
            ptr = ptr.children[idx]
        ptr.isEnd = True
        
    
    def find(self, word):
        count = 0
        n = len(word)
        ptr = self.root
        for i in range(n):
            idx = ord(word[i]) - ord('0')
            if ptr.children[idx] != None:
                count += 1
                ptr = ptr.children[idx]
            else:
                break
        
        return count
    
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        for word in arr1:
            self.insert(str(word))
            
        ans = 0    
        for word in arr2:
            ans = max(ans, self.find(str(word)))
        return ans    
#         m1 = defaultdict(int)
#         for word in arr1:
#             word = str(word)
#             for i in range(len(word)):
#                 m1[word[:i+1]] = 1
        
#         m2 = defaultdict(int)
#         for word in arr2:
#             word = str(word)
#             for i in range(len(word)):
#                 m2[word[:i+1]] = 1
                
#         keys1 = list(m1.keys())
        
#         ans = 0
#         for i in keys1:
#             if m2[i] > 0:
#                 ans = max(ans, len(i))
                
#         return ans

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
