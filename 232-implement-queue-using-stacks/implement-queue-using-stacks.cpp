class MyQueue {
public:
    stack<int> st;
    void makeTheStackCorrect(stack<int>& st){
        int x=st.top();
        st.pop();
        int t=st.top();
        st.pop();
        st.push(x);
        if(st.size()>1)makeTheStackCorrect(st);
        st.push(t);
    }
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(st.size()>=2)makeTheStackCorrect(st);
    }
    
    int pop() {
        int t=st.top();
        st.pop();
        return t;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.size()==0? true:false;
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