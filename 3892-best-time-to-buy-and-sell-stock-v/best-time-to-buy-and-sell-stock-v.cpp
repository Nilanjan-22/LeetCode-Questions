class Solution {
public:
//0 currently nno transaction
//1 ->normal
//2 -> short selling

    long long ans(int i,int type, int k, int prev,vector<int>& prices, vector<vector<vector<long long>>>& dp){
        if(k==0)return 0;
        else if(i>=prices.size() && type==2)return -prev;
        else if(i>=prices.size())return 0;

        if(dp[i][k][type]!=LLONG_MIN)return dp[i][k][type];
        //explore all posibilities
        long long profit;
        if(type==0){
            long long skip=ans(i+1,type,k,prev,prices,dp);
            long long buy = -prices[i]+ ans(i+1,1,k,0,prices,dp);
            long long sell = prices[i]+ans(i+1,2,k,prices[i],prices,dp);
            profit= max(skip,max(buy,sell));
        }
        else if(type==1){
            long long skip=ans(i+1,type,k,prev,prices,dp);
            long long sell = prices[i]+ans(i+1,0,k-1,0,prices,dp);
            profit = max(skip,sell);
        }
        else{
            long long skip=ans(i+1,type,k,prev,prices,dp);
            long long buy = -prices[i]+ans(i+1,0,k-1,0,prices,dp);
            profit = max(skip,buy);
        }
        return dp[i][k][type]=profit;

    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(n/2+1, vector<long long>(3,LLONG_MIN)));
        return ans(0,0,k,0,prices,dp);
    }
};