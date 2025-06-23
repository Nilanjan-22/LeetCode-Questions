class Solution {
public:
    int pnc(int i, int amount, int a,vector<int>&deno, vector<vector<int>>& dp){
        if(amount==0)return 1;
        if(i>=deno.size())return 0;
        if(deno[i]>amount)return 0;
        if(dp[i][amount]!=-1 && amount!=a)return dp[i][amount];
        long long cnt= pnc(i,amount-deno[i],amount,deno,dp) + pnc(i+1,amount,amount,deno,dp);

        return dp[i][amount]=cnt;
    }
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> deno;
        int n=numWays.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            int ways= pnc(0,i+1,i+1,deno,dp);
            if(numWays[i]-ways==1){
                deno.push_back(i+1);
                dp[0][i+1]=ways;
                for(int j=0;j<deno.size();j++){
                    dp[j][i+1]++;
                }
            }
            else if(ways>numWays[i] || numWays[i]-ways>1){
                return {};
            }

        }
        return deno;
    }
};