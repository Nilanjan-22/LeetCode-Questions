class Solution {
public:
    int solve(int cur, int prev, vector<string>&words, vector<vector<int>>& dp){
        if(cur>=words.size())return 0;
        if(dp[cur][prev]!=-1)return dp[cur][prev];

        int longest=solve(cur+1,prev,words,dp);

        if(prev==words.size()){
            longest=max(longest,1+solve(cur+1,cur,words,dp));
        }
        else if(words[cur].size()==words[prev].size()+1){
            int skip=0;
            bool canGo=true;
            for(int i=0;i<words[prev].size();i++){
                if(skip==1 && words[cur][i+1]!=words[prev][i]){    
                    canGo=false;
                    break;
                }
                else if(words[cur][i]!=words[prev][i]){
                    skip=1;
                    if(words[cur][i+1]!=words[prev][i]){
                        canGo=false;
                        break;
                    }
                }
            }
            if(canGo){
                longest=max(longest, 1+solve(cur+1,cur,words,dp));
            }
        }

        return dp[cur][prev]=longest;
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();});
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,n,words,dp);
    }
};