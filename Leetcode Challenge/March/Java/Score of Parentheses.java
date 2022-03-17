class Solution {
    public int scoreOfParentheses(String s) {
        Stack<Integer> st = new Stack<>();
        int score = 0;
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if(ch == '('){
                st.push(score);
                score = 0;
            }
            else {
                score = st.pop() + Math.max(2 * score, 1);
            }
        }
        return score;
    }
}

class Solution {
    public int scoreOfParentheses(String s) {
        int depth = 0, res = 0;
        char prev = '(';
        
        for (char ch:  s.toCharArray()) {
            if (ch == '(')
                depth++;
            else {
                depth--;
                if (prev == '(')
                    res += Math.pow(2, depth);
            }
            
            prev = ch;
        }
        
        return res;
    }
}
