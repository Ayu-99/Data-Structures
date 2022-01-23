public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> res = new ArrayList();
        for (int i = 1; i <= 9; i++) {
            helper(0, i, low, high, res);
        }
        Collections.sort(res);
        return res;
    }
    
    void helper(int cur, int digit, int low, int high, List<Integer> res) {    
        cur = cur * 10 + digit;
        if (cur > high)
            return;
        
        if (cur >= low) {
            res.add(cur);
        }
        
        if (digit + 1 <= 9)
            helper(cur, digit + 1, low, high, res);
    }
