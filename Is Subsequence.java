//brute
int prevIndex = -1;
for (char c : s.toCharArray()) {
    boolean found = false;
    for (int j = prevIndex + 1; j < t.length(); j++) {
        if (t.charAt(j) == c) {
            found = true;
            prevIndex = j;
            break;
        }
    }
    if (!found) return false;
}
return true;


//optimized
public boolean isSubsequence(String s, String t) {
    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
        if (s.charAt(i) == t.charAt(j)) {
            i++;
        }
        j++;
    }
    return i == s.length();
}
