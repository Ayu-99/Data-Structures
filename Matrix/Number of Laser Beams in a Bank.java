class Solution {
    public int numberOfBeams(String[] bank) {
        int rows = bank.length;
        int cols = bank[0].length();
        int lastCount=0, total=0;

        for (String str: bank) {
            int count=0;
            for (int i = 0; i < cols; i++){
                if (str.charAt(i)=='1') {
                    count++;   
                }
            }
            total += (lastCount*count);
            if (count !=0) lastCount = count;

        }
        
        return total;
    }
}
