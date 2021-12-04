class TrieNode {
    public:
    bool isEnd;
    vector<TrieNode*> child;
    TrieNode() {
        isEnd = false;
        child.assign(26, nullptr);
    }
};
class StreamChecker {
public:
    string stream = "";
    int max_len = 0;
    TrieNode* root;
    
    void insert(string s) {
        TrieNode* curr = root;
        for(int i = s.length() - 1; i >= 0; i--){
            if(!curr->child[s[i]-'a']){
                curr->child[s[i]-'a'] = new TrieNode();
            }
            curr = curr->child[s[i]-'a'];
        }
        curr->isEnd = true;
    }
    
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(auto s: words) {
            insert(s);
            int n = s.length(); 
            if(n > max_len) {
                max_len = n;
            }
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        TrieNode* curr = root;
        int curr_len = max_len;
        for(int i = stream.length() - 1; i >=0 && curr_len; i--, curr_len--) {
            if(!curr->child[stream[i] - 'a']) 
                return false;
            curr = curr->child[stream[i] - 'a'];
            if (curr->isEnd)
                return true;    
        }
        return false;
        
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
