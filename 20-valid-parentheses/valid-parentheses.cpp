class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(1);
                cnt++;
            }
            else if(s[i]=='{'){
                st.push(2);
                cnt++;
            }
            else if(s[i]=='['){
                st.push(3);
                cnt++;
            }
            else{
                cnt--;
                if(st.empty())return false;
                if(s[i]==')' && st.top()==1)st.pop();
                else if(s[i]=='}' && st.top()==2)st.pop();
                else if(s[i]==']' && st.top()==3)st.pop();
            }
        }
        if(cnt==0 && st.empty())return true;
        return false;
    }
};