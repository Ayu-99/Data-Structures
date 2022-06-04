class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        
        unordered_set<string> set;
        
        for (int i = 0; i <= s.size()-k; i++) {
            set.insert(s.substr(i, k));
        }
        
        return set.size() == pow(2, k);
    }
};
