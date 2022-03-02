class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        
        if s == "":
            return True
        if t == "":
            return False

        if len(s) == 1 and len(t) == 1:
            return s[0] == t[0]

        a = 0
        # idx=0
        b = 0
        for i in range(len(t)):
            # print(a,i)
            if a>=len(s):
                return True
            if s[a] == t[i]:

                a += 1

        # a += 1
        print(a)
        if a == len(s):
            return True
        else:
            return False
