class Solution {
public:
    int mod = 1e9+7;
    long long solve(int cur, int k, int n, vector<vector<long long>>& dp){
        if(cur+k>=n)return 0;
        if(k==0)return 1;
        if(dp[cur][k]!=-1)return dp[cur][k];
        long long possibilities=solve(cur+1,k,n,dp);
        for(int i=cur+1;i<=n-k;i++){
            possibilities += solve(i,k-1,n,dp);
            possibilities%=mod;
        }
        return dp[cur][k]=possibilities;
    }
    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n,vector<long long>(n,-1));
        return solve(0,k,n,dp);
    }
};