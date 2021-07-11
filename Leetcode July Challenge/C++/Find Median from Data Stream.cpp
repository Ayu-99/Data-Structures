#include<bits/stdc++.h>
class MedianFinder {
public:
    priority_queue<int> maxpq; //maxHeap
    priority_queue<int, vector<int>, greater<int>> minpq; //minHeap
    
    void addNum(int num) {
            
        if(maxpq.empty() || maxpq.top() > num){
            maxpq.push(num);
        }else{
            minpq.push(num);
        }
        
        if(maxpq.size() > minpq.size() + 1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(minpq.size() > maxpq.size() + 1){
            maxpq.push(minpq.top());
            minpq.pop();
        }
        
    }
    
    double findMedian() {
       if(maxpq.size() == minpq.size()){
           return (maxpq.top() + minpq.top()) / 2.0;
       }
        else{
            if(maxpq.size() > minpq.size()){
                return maxpq.top();
            }else{
                return minpq.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
