#define pi pair<int,int>

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& p, vector<int>& c) {
        int n = p.size();
        vector<pair<int,int>> projects;
        for(int i=0 ; i<n ; i++) {
            projects.push_back({p[i],c[i]});
        }  

        //capital in ascending order
        sort(projects.begin(),projects.end(),[&](pi a,pi b){
            return a.second<b.second;
        });
        
        
        priority_queue<int> pq; //max heap
        
        int i=0;
        
        while(k){ //select k projects
            while(i<n && projects[i].second<=W)     
                pq.push(projects[i++].first);
            
            if(!pq.empty()){
                W += pq.top();
                pq.pop();
            }
            k--;
        }
        
        return W;
    }
};
