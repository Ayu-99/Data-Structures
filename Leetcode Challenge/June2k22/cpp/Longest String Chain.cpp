class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<unordered_set<string>> W(17);
        for (auto word : words) 
            W[word.size()].insert(word);
        unordered_map<string, int> dp;
        int best = 1;
        for (int i = 16; i; i--) {
            if (W[i-1].empty()) continue;
            for (auto word : W[i]) {
                int wVal = dp[word] ? dp[word] : 1;
                for (int j = 0; j < word.size(); j++) {
                    string pred = word.substr(0,j) + word.substr(j+1);
                    int pVal = dp[pred] ? dp[pred] : 1;
                    if (W[i-1].find(pred) != W[i-1].end() && wVal >= pVal) {
                        dp[pred] = wVal + 1;
                        best = max(best, wVal + 1);
                    }
                }
            }
        }
        return best;
    }
};
