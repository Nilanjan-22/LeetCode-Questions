class Solution {
public:
    int ways(int i,int n,int x, vector<vector<int>>& dp){
        if(n==0)return 1;
        if(pow(i,x)>n)return 0;
        if(dp[i][n]!=-1)return dp[i][n];
        int m=1e9+7;
        //take
        long long tk= ways(i+1,n-pow(i,x),x,dp)%m;
        long long ntk= ways(i+1,n,x,dp)%m;

        return dp[i][n]=(tk+ntk)%m;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return ways(1,n,x,dp);
    }
};