class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        n = len(s)
        # step 1:
        if n <= 10:
            return []
        # step 2:
        d = dict()
        for i in range(n-9):
            key = s[i:i+10] #keeping a window of size 10
            if q
                d[key] = 1
            else:
                d[key] += 1
        # step 3:
        return [key for key in d.keys() if d[key] > 1] #return all the repeative strings
