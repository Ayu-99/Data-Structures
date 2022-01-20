class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;  //1 -----> 1000000000 m
        int right = 1000000000;
        
        while(left <= right){
            int mid = left + (right - left) / 2; //k
            if(canEatInTime(piles, mid, h)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
    bool canEatInTime(vector<int>& piles, int k, int h){
        int hours = 0;
        for(int pile : piles){
            int div = pile / k;
            hours += div;
            if(pile % k != 0) hours++;
            
        }
        return hours <= h;
    }
};
