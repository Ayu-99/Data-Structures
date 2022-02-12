class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()); //O(1) searching time
        queue<pair<string,int>> todo;
        todo.push({beginWord, 1});
        while (!todo.empty()) {
                pair<string,int> p = todo.front();
                string word = p.first;
                int ladder = p.second;
                todo.pop();
                if (word == endWord) {
                    return ladder;
                }
                dict.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            todo.push({word, ladder+1});
                        }
                     }
                    word[j] = c;
                }    
            
        }
        return 0;
    }
};
