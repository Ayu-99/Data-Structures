class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int total = 0;
        for(int i = 0; i < flowerbed.size() && total < n; i++) {
            if(flowerbed[i] == 0) {
               int next = (i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1]; 
               int prev = (i == 0) ? 0 : flowerbed[i - 1];
               if(next == 0 && prev == 0) {
                   flowerbed[i] = 1;
                   total++;
               }
            }
        }
        
        return total == n;//true -- equal
    }
};
