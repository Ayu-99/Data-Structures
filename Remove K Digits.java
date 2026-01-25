public String removeKdigits(String num, int k) {
    Stack<Character> st = new Stack<>();

    for (char c : num.toCharArray()) {
        while (!st.isEmpty() && k > 0 && st.peek() > c) {
            st.pop();
            k--;
        }
        st.push(c);
    }

    // if k still left, remove from end
    while (k-- > 0 && !st.isEmpty()) {
        st.pop();
    }

    // build result & remove leading zeros
    StringBuilder sb = new StringBuilder();
    for (char c : st) sb.append(c);

    int i = 0;
    while (i < sb.length() && sb.charAt(i) == '0') i++;

    return i == sb.length() ? "0" : sb.substring(i);
}
