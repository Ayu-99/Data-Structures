//making pop operation costly
class MyStack {
public:
    
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }
    
    void push(int x) {
        
        q1.push(x);
        
        
    }
    
    int pop() {
        
        int n = q1.size();
        while(n > 1) {
            int e = q1.front();
            q2.push(e);
            q1.pop();
            n--;
        }
        int x = q1.front();
        q1.pop();
        
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return x;
        
    }
    
    int top() {
        int n = q1.size();
        while(n > 1) {
            int e = q1.front();
            q2.push(e);
            q1.pop();
            n--;
        }
        int x = q1.front();
        q1.pop();
        
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        q1.push(x);
        return x;

    }
    
    bool empty() {
        return q1.empty();
    }
};



//making push operation costly
class MyStack {
public:
    
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }
    
    void push(int x) {
        
        q2.push(x);
 
        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
 
        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        
    }
    
    int pop() {
        
        if (q1.empty())
            return 0;
        int x=q1.front();
        q1.pop();
        return x;
        
    }
    
    int top() {
               return q1.front();

    }
    
    bool empty() {
        return q1.empty();
    }
};





//using only 1 queue
class MyStack {
public:
	queue<int> que;
	// Push element x onto stack.
	void push(int x) {
		que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}
	}

	// Removes the element on top of the stack.
	int pop() {
		int x = que.front();
        que.pop();
        return x;
	}

	// Get the top element.
	int top() {
		return que.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return que.empty();
	}
};
