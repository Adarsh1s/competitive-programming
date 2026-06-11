class MyQueue {
private:
    stack<int> x1;
    stack<int> y1;
public:
    MyQueue() {
    }
    
    void push(int x) {
        x1.push(x);
    }
    
    int pop() {
        while(!x1.empty()){
            y1.push(x1.top());
            x1.pop();
        }
        int temp = y1.top();
        y1.pop();
        while(!y1.empty()){
            x1.push(y1.top());
            y1.pop();
        }
        return temp;
    }
    
    int peek() {
        while(!x1.empty()){
            y1.push(x1.top());
            x1.pop();
        }
        int temp = y1.top();
        while(!y1.empty()){
            x1.push(y1.top());
            y1.pop();
        }
        return temp;
    }
    
    bool empty() {
        while(!x1.empty()){
            y1.push(x1.top());
            x1.pop();
        }
        return y1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */