class Solution {
public:
    bool isPossible(int mid,vector<int>& weights,int days){
        int count = 1, sum = 0;
        
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > mid) {
                count++;
                sum = weights[i];
            }
        }
        if (count <= days)
            return true;
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCapacity=0;
        int n = weights.size();
        
        for(int i = 0; i < n; i++)
            maxCapacity += weights[i];
        
        int low = *max_element(weights.begin(), weights.end()), high = maxCapacity;
        int result;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, weights, days)) {
                result = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return result;
    }
};
