//brute
class Solution {
    public char findTheDifference(String s, String t) {
        Map<Character, Integer> map = new HashMap<>();

        for (char c : s.toCharArray())
            map.put(c, map.getOrDefault(c, 0) + 1);

        for (char c : t.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) - 1);
            if (map.get(c) < 0)
                return c;
        }

        return ' ';
    }
}


//optimized
class Solution {
    public char findTheDifference(String s, String t) {
        int x = 0;
        for (char c : (s + t).toCharArray())
            x ^= c;
        return (char) x;
    }
}
