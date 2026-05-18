class Solution {
public:
    int solve(int i, int sum, int amount, vector<int>&coins , vector<vector<int>>& dp){
        if(sum==amount)return 0;
        if(i>=coins.size() || sum>amount)return 1e5;

        if(dp[i][sum]!=-1)return dp[i][sum];
        int minChange=1e9;

        minChange = min(minChange,solve(i+1,sum,amount,coins,dp));

        if(coins[i]<=amount-sum)minChange = min(minChange,1+solve(i,sum+coins[i],amount,coins,dp));

        return dp[i][sum]=minChange;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int minChange=solve(0,0,amount,coins,dp);
        if(minChange>1e4)return -1;
        return minChange;
    }
};