class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& p, int start, int end) {
        
        
        unordered_map<int,vector<pair<int,double>>> m;
        for(int i=0;i<e.size();i++){
            
            m[e[i][0]].push_back({e[i][1], p[i]});
            m[e[i][1]].push_back({e[i][0], p[i]});
            
        }
        
        vector<double> dis(n,0),vis(n);
        priority_queue<pair<double,int>> q; //max heap
        q.push({1,start});
        while(!q.empty()){
            auto a=q.top();
            q.pop();
            if(vis[a.second])continue;
            vis[a.second]=1;
            for(auto c:m[a.second]){
                if(!vis[c.first]){
                    if(dis[c.first]<c.second*a.first){
                        dis[c.first]=c.second*a.first;
                        q.push({dis[c.first],c.first});
                    }
                }
                
            }
            
        }
        
        return dis[end];
        q
    }
};
