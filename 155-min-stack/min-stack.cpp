class MinStack {
public:
    stack<int> min;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(min.empty() || min.top()>=st.top())min.push(value);
    }
    
    void pop() {
        if(min.top()==st.top())min.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */