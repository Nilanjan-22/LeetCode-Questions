class Solution {
public:
    int solve(int i, int cur, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(cur==amount)return 1;
        if(i>=coins.size() || cur>amount)return 0;

        if(dp[i][cur]!=-1)return dp[i][cur];

        int ways=0;

        ways+=solve(i+1,cur,amount,coins,dp);
        if(coins[i]<=amount-cur)ways+=solve(i,cur+coins[i],amount,coins,dp);

        return dp[i][cur]=ways;;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount,-1));
        return solve(0,0,amount,coins,dp);
    }
};