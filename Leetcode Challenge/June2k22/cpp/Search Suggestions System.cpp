// class Solution {
// public:
//     vector<vector<string>> suggestedProducts(vector<string> &products,
//                                              string searchWord) {
//         sort(products.begin(), products.end());
//         vector<vector<string>> result;
//         int start, bsStart = 0, n=products.size();
//         string prefix;
//         for (char &c : searchWord) {
//             prefix += c;

//             start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();

//             result.push_back({});
//             for (int i = start; i < min(start + 3, n) && !products[i].compare(0, prefix.length(), prefix); i++)
//                 result.back().push_back(products[i]);

//             bsStart = start;
//         }
//         return result;
//     }
// };

struct TrieNode {
    TrieNode *children[26] = {NULL};
    bool endOfWord = false;
};
class Solution {
public:
    void insertWord(TrieNode *trie, string &word) {
        for (char &c : word) {
            int index = c - 'a';
            if (!trie->children[index])
                trie->children[index] = new TrieNode;
            trie = trie->children[index];
        }
        trie->endOfWord = true;
    }
    vector<string> searchWord(TrieNode *trie, string &prefix) {
        vector<string> result;
        for (char &c : prefix) {
            int index = c - 'a';
            if (!trie->children[index])
                return {};
            trie = trie->children[index];
        }
        dfs(trie, prefix, result);
        return result;
    }
    void dfs(TrieNode *trie, string pre, vector<string> &result) {
        if (result.size() == 3)
            return;
        if (trie->endOfWord)
            result.push_back(pre);
        
        for (int i = 0; i < 26; i++) {
            if (trie->children[i])
                dfs(trie->children[i], pre + (char)(i + 'a'), result);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        TrieNode *trie = new TrieNode;
        for (string &prod : products)
            insertWord(trie, prod);
        vector<vector<string>> result;
        string prefix;
        for (char &c : search) {
            prefix += c;
            result.push_back(searchWord(trie, prefix));
        }
        return result;
    }
};
