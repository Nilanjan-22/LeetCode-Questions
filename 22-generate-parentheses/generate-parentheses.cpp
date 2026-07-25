class Solution {
public:
    bool checkParenthesis(string& gen){
        stack<char> st;
        for(int i=0;i<gen.size();i++){
            if(gen[i]=='(')st.push('(');
            else {
                if(st.empty())return false;
                st.pop();
            }
        }
        if(st.empty())return true;
        return false;
    }
    void solve(int i, int n, string& gen, vector<string>& ans){
        if(i==n){
            if(checkParenthesis(gen))ans.push_back(gen);
            return;
        }

        gen.push_back('(');
        solve(i+1,n,gen,ans);
        gen.pop_back();
        gen.push_back(')');
        solve(i+1,n,gen,ans);
        gen.pop_back();
        return;

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string gen = "";
        solve(0,2*n,gen,ans);
        return ans;
    }
};