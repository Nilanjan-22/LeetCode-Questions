class Solution {
public:
    string trimTrailingVowels(string s) {
        string ans;
        bool f=false;
        for(int i=s.size()-1;i>=0;i--){
            if((s[i]!='a' &&s[i]!='e' &&s[i]!='i' && s[i]!='o' && s[i]!='u') || f){
                f=true;
                ans.push_back(s[i]);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};