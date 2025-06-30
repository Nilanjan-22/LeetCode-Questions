class Solution {
public:
    vector<string> partitionString(string s) {
        set<string> st;
        string seg="";
        vector<string> ans;
        int n=s.size();
        for(int i=0;i<n;i++){
            seg.push_back(s[i]);
            if(st.find(seg)==st.end()){
                st.insert(seg);
                ans.push_back(seg);
                seg="";
            }
        }
        return ans;
        
    }
};