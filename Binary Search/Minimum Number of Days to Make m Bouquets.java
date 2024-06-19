class Solution {

    public int getNumberOfBouqets(int[] bloomDay, int mid, int k) {
        int numberOfBouqets = 0;
        int count = 0;
        for (int i=0; i < bloomDay.length; i++) {
            if (bloomDay[i] <= mid) {
                count++;
            }else{
                count=0;
            }

            if (count==k) {
                numberOfBouqets++;
                count=0;
            }
        }
        return numberOfBouqets;

    }

    public int minDays(int[] bloomDay, int m, int k) {
        int low=0, high=0;
        for (int day: bloomDay) {
            high = Math.max(high, day);
        }

        int minDays= -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (getNumberOfBouqets(bloomDay, mid, k) >= m) {
                minDays = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return minDays;
    }
}
