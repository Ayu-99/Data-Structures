class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        char seen[128] = {};
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (!seen[c]) {
                for (char s: seen) if (s == t[i]) return false;
                seen[c] = t[i];
            }
            else if (seen[c] != t[i]) return false;
        }
        return true;
    }
    
    // bool isIsomorphic(string s, string t) {
    //     char map_s[128] = { 0 };
    //     char map_t[128] = { 0 };
    //     int len = s.size();
    //     for (int i = 0; i < len; ++i)
    //     {
    //         if (map_s[s[i]]!=map_t[t[i]]) return false;
    //         map_s[s[i]] = i+1;
    //         map_t[t[i]] = i+1;
    //     }
    //     return true;    
    // }
};
