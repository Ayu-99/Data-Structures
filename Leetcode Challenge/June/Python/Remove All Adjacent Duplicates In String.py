class Solution:
    def removeDuplicates(self, s: str) -> str:
        st = []
        ans=''
        for i in range(len(s)):
            if len(st) == 0:
                st.append(s[i])
            
            elif st[-1] == s[i]:
                st.pop()
            
            else:
                st.append(s[i])
                
        
        while len(st)>0:
            ans += st[-1]
            st.pop()
        return ans[::-1]
            
        
