//brute force approach
public class StringRotationBruteForce {

    public static boolean isRotation(String s1, String s2) {
        // Length check
        if (s1.length() != s2.length()) {
            return false;
        }

        int n = s1.length();
        String rotated = s1;

        // Generate all rotations
        for (int i = 0; i < n; i++) {
            // Rotate left by 1
            rotated = rotated.substring(1) + rotated.charAt(0);

            // Check match
            if (rotated.equals(s2)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        String s1 = "abcd";
        String s2 = "cdab";

        System.out.println(isRotation(s1, s2)); // true
    }
}


//optimized code - using KMP alogrithm
public class StringRotationKMP {

    // Build LPS array
    private static int[] buildLPS(String pattern) {
        int m = pattern.length();
        int[] lps = new int[m];

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // KMP search
    private static boolean kmpSearch(String text, String pattern) {
        int n = text.length();
        int m = pattern.length();

        int[] lps = buildLPS(pattern);

        int i = 0; // text index
        int j = 0; // pattern index

        while (i < n) {
            if (text.charAt(i) == pattern.charAt(j)) {
                i++;
                j++;
            }

            if (j == m) {
                return true; // pattern found
            } else if (i < n && text.charAt(i) != pattern.charAt(j)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

    // Rotation check using KMP
    public static boolean isRotation(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        String combined = s1 + s1;
        return kmpSearch(combined, s2);
    }

    public static void main(String[] args) {
        String s1 = "abcd";
        String s2 = "cdab";

        System.out.println(isRotation(s1, s2)); // true
    }
}


