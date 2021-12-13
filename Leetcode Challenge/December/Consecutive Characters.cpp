class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int x = 1;
        for(int i = 1; i < s.length(); i++){
            if(s[i-1] == s[i]) {
                x++;
            } else {
                ans = max(ans, x);
                x = 1;
            }
        }
        
        ans = max(ans, x);
        return ans;
    }
};
