class Solution {
public:
    int solve(int i, int t, vector<int>& prices, vector<vector<int>>& dp){
        if(i>=prices.size())return 0;
        if(dp[i][t]!=-1)return dp[i][t];

        int maxReturn=0;
        if(t==0){
            maxReturn = -prices[i]+solve(i+1,1,prices,dp);
        }
        else {
            maxReturn = prices[i]+solve(i+2,0,prices,dp);
        }

        maxReturn = max(maxReturn, solve(i+1,t,prices,dp));

        return dp[i][t]=maxReturn;
    }  
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,0,prices,dp);
    }
};