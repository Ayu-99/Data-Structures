def countVowelPermutation(self, n: int) -> int:
        m = (10**9+7)
        from functools import lru_cache
        
        @lru_cache(None)
        def helper(last, n):
            if n==1:
                if last==None:
                    return 5
                else:
                    if last=='a':
                        return 1
                    if last=='e':
                        return 2
                    if last=='i':
                        return 4
                    if last=='o':
                        return 2
                    if last=='u':
                        return 1
                
            ans  = 0
            if last==None:
                ans += helper('a', n-1)+helper('e', n-1)+helper('i', n-1)+helper('o', n-1)+helper('u', n-1)
                ans %= m
            else:
                if last == 'a':
                    ans += helper('e', n-1)
                    ans %= m
                if last == 'e':
                    ans += helper('a', n-1)+helper('i', n-1)
                    ans %= m
                if last == 'i':
                    ans += helper('a', n-1)+helper('e', n-1)+helper('o', n-1)+helper('u', n-1)
                    ans %= m
                if last == 'o':
                    ans += helper('i', n-1)+helper('u', n-1)
                    ans %= m
                if last == 'u':
                    ans += helper('a', n-1)
                    ans %= m
                    
            return ans    
            
        return helper(None, n)
