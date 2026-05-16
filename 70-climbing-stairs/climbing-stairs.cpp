class Solution {
public:
    int solve(int i, int destination, vector<int>& dp){
        if(i==destination)return 1;
        if(i>destination)return 0;
        if(dp[i]!=-1)return dp[i];

        return dp[i]=solve(i+1,destination,dp)+solve(i+2,destination,dp);

    }
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(i>1){
                dp[i]+=dp[i-2];
            }
            dp[i]+=dp[i-1];
        }
        return dp[n];
    }
};