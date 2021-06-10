class MyCalendar {
    private:
        vector<pair<int, int>> m;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto it : m) {
            if(it.first<end && start<it.second){
                return false;
            }
        }
        m.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
