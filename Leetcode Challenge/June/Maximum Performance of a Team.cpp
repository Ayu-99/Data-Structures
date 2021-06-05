class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> v;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i], speed[i]});
        }
        
        long sum=0,ans=0;
        sort(v.begin(),v.end());
        for(auto i=n-1;i>=0;i--){
            
            sum +=v[i].second;
            pq.push(v[i].second);
            if(pq.size()>k){
                sum-= pq.top();
                pq.pop();
            }
            
            ans=max(ans, sum*v[i].first);
        }
        
        return ans%1000000007;
    }
};
