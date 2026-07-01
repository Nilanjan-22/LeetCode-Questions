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
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return n-longestPal(0,n-1,s,dp);
    }
};