class Solution {
public:
    int removePalindromeSub(string s) {
        int i=0, j = s.size()-1;
        bool isPalindrome=true;
        while(i<=j) {
            if(s[i] != s[j]) isPalindrome=false;
            i++;
            j--;
        }
        
        if(isPalindrome) return 1;
        return 2;
    }
};
