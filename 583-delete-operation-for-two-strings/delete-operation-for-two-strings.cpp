class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i>=s1.size())return s2.size()-j;
        if(j>=s2.size())return s1.size()-i;

        if(dp[i][j]!=-1)return dp[i][j];

        int minDeletions=INT_MAX;

        if(s1[i]==s2[j])return dp[i][j]=solve(i+1,j+1,s1,s2,dp);

        minDeletions = min( minDeletions, 1+solve(i+1,j,s1,s2,dp));
        minDeletions= min( minDeletions, 1+solve(i,j+1,s1,s2,dp));

        return dp[i][j]= minDeletions;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(1+dp[i-1][j], 1+dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
