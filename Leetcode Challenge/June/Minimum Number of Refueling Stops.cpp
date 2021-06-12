class Solution {
public:
     int minRefuelStops(int target, int cur, vector<vector<int>> s) {
        int i = 0, res;
        priority_queue<int>pq;
        for (res = 0; cur < target; res++) {
            while (i < s.size() && s[i][0] <= cur)
                pq.push(s[i++][1]);
            if (pq.empty()) return -1;
            cur += pq.top(), pq.pop();
        }
         // cout<<cur<<endl;
        return res;
    }
};
