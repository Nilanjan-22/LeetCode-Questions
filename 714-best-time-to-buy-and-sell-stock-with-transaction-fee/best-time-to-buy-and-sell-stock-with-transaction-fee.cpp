class Solution {
public:
    int solve(int i, int t,int fee, vector<int>& prices, vector<vector<int>>& dp){
        if(i>=prices.size())return 0;
        if(dp[i][t]!=-1)return dp[i][t];

        int maxReturn=0;
        if(t==0){
            maxReturn = -prices[i]+solve(i+1,1,fee,prices,dp);
        }
        else {
            maxReturn = prices[i]+solve(i+1,0,fee,prices,dp)-fee;
        }

        maxReturn = max(maxReturn, solve(i+1,t,fee,prices,dp));

        return dp[i][t]=maxReturn;
    }  
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,0,fee,prices,dp);
    }
};