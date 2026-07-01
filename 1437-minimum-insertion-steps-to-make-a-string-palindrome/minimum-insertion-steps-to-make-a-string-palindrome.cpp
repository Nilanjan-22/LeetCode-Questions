class Solution {
public:
    int longestPal(int i, int j, string& s, vector<vector<int>>& dp){
        if(i>=s.size() || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j]=1+longestPal(i+1,j-1,s,dp);
        }
        return dp[i][j]=max(longestPal(i+1,j,s,dp),longestPal(i,j-1,s,dp));
    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<n+1;j++){
                if(s[i]==s[j-1]){
                    dp[i][j]=1+dp[i+1][j-1];
                }
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return n-dp[0][n];
    }
};