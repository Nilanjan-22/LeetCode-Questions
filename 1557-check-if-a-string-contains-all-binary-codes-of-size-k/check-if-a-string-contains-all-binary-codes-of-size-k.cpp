class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        if(s.size()<k)return false;
        for(int i=0; i<s.size()-k+1;i++){
            st.insert(s.substr(i,k));
        }
        int need=pow(2,k);
        if(st.size()==need)return true;
        return false;
    }
};