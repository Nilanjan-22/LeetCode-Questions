class Solution {
public:
    int solve (int i, int j, vector<int>& v,vector<vector<int>>& dp){
        if(j>=v.size() || i<0 || j-i<2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int res=INT_MAX;
        for(int k=i+1; k<j; k++){
            int wt= v[i]*v[j]*v[k] + solve(i,k,v,dp) + solve(k,j,v,dp);
            res=min(res,wt);
        }
        return dp[i][j]=res;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,values,dp);
    }
};