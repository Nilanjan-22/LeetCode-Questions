class Solution {
public:
    string trimTrailingVowels(string s) {
        bool cons=false;
        set<char> st ={'a','e','i','o','u'};
        string ans;
        for(int i=s.size()-1;i>=0;i--){
            if(!cons && st.find(s[i])!=st.end()){
                continue;
            }
            else{
                cons=true;
                ans.push_back(s[i]);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};