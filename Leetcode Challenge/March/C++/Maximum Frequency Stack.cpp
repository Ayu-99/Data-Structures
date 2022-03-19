class FreqStack {
    //max-heap
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_map<int, int> freq; 
    int pos = 0;
public:
    void push(int x) {
        pq.push(make_pair(++freq[x], make_pair(++pos, x)));
    }
    
    int pop() {
        auto val = pq.top();
        pq.pop();
        int x = val.second.second;
        freq[x]--;
        return x;
    }
};
