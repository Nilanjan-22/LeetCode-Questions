class Solution {
public:
    long long ans(int i,int o, vector<int>& p, int k, vector<vector<vector<long long>>>& dp){
        
        if(i==p.size()-1){
            if(o==2)return 0;
            if(o==1) return -p[i]; 
            return p[i];
        }
        if(k==0)return 0;
        if(dp[i][o][k]!=-1)return dp[i][o][k];
        long long profit;
        if(o==2){
            // buy
            long long buy = -p[i] + ans(i+1,0,p,k,dp);
            //sell
            long long sell = p[i]+ ans(i+1,1,p,k,dp);
            // dont do anything 
            long long dnd = ans(i+1,2,p,k,dp);

            profit= max(buy,max(sell,dnd));
        }
        else if(o==1){
            long long buy= -p[i] + ans(i+1,2,p,k-1,dp);
            long long dnd = ans(i+1,1,p,k,dp);
            profit= max(dnd,buy);
        }
        else{
            long long sell = p[i]+ans(i+1,2,p,k-1,dp);
            long long dnd = ans(i+1,0,p,k,dp);
            profit = max(sell,dnd);
        }
        return dp[i][o][k]=profit;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(3,vector<long long>(k+1,-1)));
        return ans(0,2,prices,k,dp);

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<3;j++){
        //         for(int l=0;l<k+1;l++){
        //             cout<<dp[i][j][l]<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }
        // return dp[0][2][k];
    }
};