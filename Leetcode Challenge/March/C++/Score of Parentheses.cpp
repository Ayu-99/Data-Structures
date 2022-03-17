// class Solution {
// public:
//     int scoreOfParentheses(string s) {
//         stack<int> st;
//         int score = 0;
//         for(int i = 0; i < s.size(); i++){
//             if(s[i] == '('){
//                 st.push(score);
//                 score = 0;
//             }
//             else {
//                 score = st.top() + max(2 * score, 1);
//                 st.pop();
//             }
//         }
//         return score;
//     }
// };

class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0, res = 0;
        char prev = '(';
        
        for (const char &ch: s) {
            if (ch == '(')
                depth++;
            else {
                depth--;
                if (prev == '(')
                    res += pow(2, depth);
            }
            
            prev = ch;
        }
        
        return res;
    }
};
