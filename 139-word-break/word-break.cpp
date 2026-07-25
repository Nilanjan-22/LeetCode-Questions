class Solution {
public:
    bool solve(int st, int en, string s, set<string>& dict, vector<vector<int>>& dp){
        if(st==en)return true;
        if(dp[st][en]!=-1)return dp[st][en];
        string str = "";

        bool isPos=false;
        for(int i=st;i<en;i++){
            str.push_back(s[i]);
            if(dict.find(str)!=dict.end()){
                isPos|=solve(i+1,en,s,dict,dp);
            }
        }
        return dp[st][en]=isPos;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(auto s: wordDict){
            dict.insert(s);
        }

        return solve(0,n,s,dict,dp);
    }
};