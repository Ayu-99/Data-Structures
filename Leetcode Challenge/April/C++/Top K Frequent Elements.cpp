class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        for(auto i : nums) {
            counts[i]++;
        }
        
        for(auto & i : counts) {
            min_heap.push({i.second, i.first});
            if(min_heap.size() > k) {
                min_heap.pop();
            }
        }
        
        vector<int> res;
         while(k--)
        {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};
