class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i==m-1 && j==n-1)return 1;
        if(i>=m || j>=n)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int totalWays=0;
        totalWays+=solve(i+1,j,m,n,dp);
        totalWays+=solve(i,j+1,m,n,dp);

        return dp[i][j]=totalWays;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1)continue;
                int totalWays=0;
                totalWays+=dp[i+1][j];
                totalWays+=dp[i][j+1];

                dp[i][j]=totalWays;
            }
        }
        return dp[0][0];
    }
};