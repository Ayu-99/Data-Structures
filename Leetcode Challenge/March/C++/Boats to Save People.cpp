class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0;
        int n = people.size();
        int l = 0, r = n-1;
        while(l <= r) {
            if(people[l] + people[r] <= limit) {
                l++;
                r--;
            } else {
                r--;
            }
            count++;
        }
     
       
        // int current_weight = people[0];
        // for(int i = 1; i < n; i++) {
        //     if((current_weight + people[i]) > limit) {
        //         current_weight = people[i];
        //         count++;
        //     } else {
        //         current_weight += people[i];
        //     }
        // }
       
        return count;
       
    }
};
