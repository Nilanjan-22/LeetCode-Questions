class Solution {
public:
    bool isPalindrome(int i, int j, string& s){
        while(i<j){
            if(s[j]!=s[i])return false;
            j--;
            i++;
        }
        return true;
    }
    
    void allPalindromePartitions(int i, string& s, vector<string>& temp, vector<vector<string>>& ans){
        if(i>=s.size()){
            ans.push_back(temp);
            return;
        }

        for(int it=i;it<s.size();it++){
            if(isPalindrome(i,it,s)){
                temp.push_back(s.substr(i,it-i+1));
                allPalindromePartitions(it+1,s,temp,ans);
                temp.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        allPalindromePartitions(0,s,temp,ans);
        return ans;
    }
};