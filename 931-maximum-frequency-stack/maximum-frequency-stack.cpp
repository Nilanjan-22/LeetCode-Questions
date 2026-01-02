class FreqStack {
public:
    vector<stack<int>> v;
    map<int,int> frq;
    FreqStack() {
        stack<int> temp ={};
        v.resize(1,temp);
    }
    
    void push(int val) {
        frq[val]++;
        if(v.size()<frq[val]){
            stack<int> temp ={};
            v.push_back(temp);
        }
        v[frq[val]-1].push(val);
    }
    
    int pop() {
        int s=v.size()-1;
        int maxf=v[s].top();
        frq[maxf]--;
        v[s].pop();
        if(v[s].empty() && s!=0){
            v.pop_back();
        }
        return maxf;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */