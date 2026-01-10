//brute
boolean validPalindrome(String s) {
    if (isPalindrome(s)) return true;

    for (int i = 0; i < s.length(); i++) {
        String temp = s.substring(0, i) + s.substring(i + 1);
        if (isPalindrome(temp)) return true;
    }
    return false;
}

boolean isPalindrome(String s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s.charAt(l++) != s.charAt(r--)) return false;
    }
    return true;
}


//optimized

boolean validPalindrome(String s) {
    int l = 0, r = s.length() - 1;

    while (l < r) {
        if (s.charAt(l) == s.charAt(r)) {
            l++;
            r--;
        } else {
            return isPalindrome(s, l + 1, r)
                || isPalindrome(s, l, r - 1);
        }
    }
    return true;
}

boolean isPalindrome(String s, int l, int r) {
    while (l < r) {
        if (s.charAt(l) != s.charAt(r)) return false;
        l++;
        r--;
    }
    return true;
}
