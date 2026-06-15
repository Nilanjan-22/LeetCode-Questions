class Solution {
public:
    int minCoins(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(amount==0)return 0;
        if(amount<0 || i>=coins.size())return 1e9;
        if(dp[i][amount]!=-1)return dp[i][amount];

        int take=1+minCoins(i,amount-coins[i],coins,dp);
        int notTake=0+minCoins(i+1,amount,coins,dp);

        return dp[i][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int val=minCoins(0,amount,coins,dp);
        if(val>=1e9)return -1;
        return val;
    }
};