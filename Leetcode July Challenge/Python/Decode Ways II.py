class Solution:
    def numDecodings(self, s: str) -> int:
        memo = dict()
        def backtrack(index):
            if index == len(s):
                return 1
            if index in memo:
                return memo[index]
            if s[index] == '0':
                return 0
            res = 0
            mult = 9 if s[index] == '*' else 1
            res += mult*backtrack(index+1)
            if index < len(s)-1:
                nextt = s[index+1]
                opts = 0
                if s[index] == '*':
                    if nextt == '*':
                        opts = 15 
                    else:
                        if nextt <= '6':
                            opts = 2 
                        else:
                            opts = 1 
                elif s[index] < '3':
                    if nextt == '*':
                        if s[index] == '1':
                            opts = 9 # 11-19
                        else:
                            opts = 6 # 21-26
                    else:
                        if int(s[index:index+2]) <= 26:
                            opts = 1
                if opts:
                    res += opts*backtrack(index+2)
            memo[index] = res%(10**9 + 7)
            return memo[index]
        return backtrack(0)
