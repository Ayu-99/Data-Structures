import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == 'c') {
                if (stack.size() < 2) return false;
                if (stack.pop() != 'b') return false;
                if (stack.pop() != 'a') return false;
            } else {
                stack.push(c);
            }
        }

        return stack.isEmpty();
    }
}
