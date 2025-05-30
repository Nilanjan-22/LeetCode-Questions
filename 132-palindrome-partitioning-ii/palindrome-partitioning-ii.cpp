class Solution {
public:
    bool checkP(int i, int j, string& s){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    int ans(int i, string& s, vector<int>& dp){
        if(i>=s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<s.size();j++){
            int cnt=INT_MAX;
            if(checkP(i,j,s)) {
                cnt = 1+ans(j+1,s,dp);
                mini=min(mini,cnt);
            }
        }
        return dp[i]= mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                int cnt=INT_MAX;
                if(checkP(i,j,s)) {
                    cnt = 1+ dp[j+1];
                    mini=min(mini,cnt);
                }
            }
            dp[i]= mini;
        }
        return dp[0]-1;
    }
};