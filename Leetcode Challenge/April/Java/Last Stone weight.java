  int lastStoneWeight(vector<int>& A) {
        priority_queue<int> pq(begin(A), end(A));
        while (pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if (x > y) pq.push(x - y);
        }
        return pq.empty() ? 0 : pq.top();
    }
