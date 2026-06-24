class MyStack {
public:
    queue<int> q;
    int size;
    MyStack() {
        size=0;
    }
    
    void push(int x) {
        q.push(x);
        int i=0;
        while(i<size){
            int t=q.front();
            q.pop();
            q.push(t);
            i++;
        }
        size++;
    }
    
    int pop() {
        int t=q.front();
        q.pop();
        size--;
        return t;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return size==0? true:false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */