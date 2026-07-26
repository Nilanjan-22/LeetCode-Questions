class Solution {
public:
    bool checkPalindrome(int st, int en, string& s){
        while(st<en){
            if(s[st++]!=s[en--])return false;
        }
        return true;
    }

    void solve(int i, string& s, vector<vector<string>>& ans, vector<string>& palindromes){
        if(i>=s.size()){
            ans.push_back(palindromes);
            return;
        }

        for(int it=i;it<s.size();it++){
            if(checkPalindrome(i,it,s)){
                palindromes.push_back(s.substr(i,it-i+1));
                solve(it+1,s,ans,palindromes);
                palindromes.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> palindromes;
        solve(0,s,ans,palindromes);
        return ans;
    }
};