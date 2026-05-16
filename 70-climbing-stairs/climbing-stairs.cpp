class Solution {
public:
    int solve(int i, int destination, vector<int>& dp){
        if(i==destination)return 1;
        if(i>destination)return 0;
        if(dp[i]!=-1)return dp[i];

        return dp[i]=solve(i+1,destination,dp)+solve(i+2,destination,dp);

    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(0,n,dp);
    }
};