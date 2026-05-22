class Solution {
public:
    int solve(int i, int t, int c, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(i>=prices.size())return 0;
        if(c>1)return 0;
        if(dp[i][t][c]!=-1)return dp[i][t][c];

        int maxReturn=0;
        if(t==0){
            maxReturn = -prices[i]+solve(i+1,1,c,prices,dp);
        }
        else {
            maxReturn = prices[i]+solve(i+1,0,c+1,prices,dp);
        }

        maxReturn = max(maxReturn, solve(i+1,t,c,prices,dp));

        return dp[i][t][c]=maxReturn;
    }  
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,0,0,prices,dp);
    }
};