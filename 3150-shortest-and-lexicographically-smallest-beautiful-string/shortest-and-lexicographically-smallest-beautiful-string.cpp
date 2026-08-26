class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int cnt1=0;
        int i=0, j=0;
        set<string> st;
        int len=INT_MAX;
        while(j<s.size()){
            if(s[j]=='1')cnt1++;
            while(cnt1>=k){
                if(j-i+1<=len && cnt1==k){
                    if(len>j-i+1)st.clear();
                    st.insert(s.substr(i,j-i+1));
                    len=j-i+1;
                }
                if(s[i]=='1')cnt1--;
                i++;
            }
            j++;
        }
        if(st.empty())return "";
        return *st.begin();
    }
};