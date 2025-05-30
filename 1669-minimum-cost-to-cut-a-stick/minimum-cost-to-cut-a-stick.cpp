class Solution {
public:
//Tabulation solution
    int ans(int i, int j,int n, vector<int>& cuts,vector<vector<int>>& dp){
        if(n==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int cost=INT_MAX;
        for(int k=i+1; k<j;k++){
            if(cuts[k]>cuts[i] && cuts[k]<cuts[j]){
                int cost_take=n+ans(i,k,cuts[k]-cuts[i],cuts,dp) + ans(k,j,cuts[j]-cuts[k],cuts,dp);
                cost=min(cost,cost_take);
            }
        }
        if(cost==INT_MAX)return dp[i][j] = 0;
        return dp[i][j] = cost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int s= cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(s,vector<int>(s,0));
        for(int i=s-1;i>=0;i--){
            for(int j=i+1;j<s;j++){
                int cost=INT_MAX;
                for(int k=i+1; k<j;k++){
                    if(cuts[k]>cuts[i] && cuts[k]<cuts[j]){
                        int cost_take=cuts[j]-cuts[i]+dp[i][k]+ dp[k][j];
                        cost=min(cost,cost_take);
                    }
                }
                if(cost==INT_MAX)dp[i][j] = 0;
                else dp[i][j] = cost;
            }
        }
        return dp[0][s-1];
    }

};