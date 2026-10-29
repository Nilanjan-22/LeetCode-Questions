class Solution {
public:
    int helper(int i, int j, int xr, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(i>=grid.size() || j>=grid[0].size())return 1024;
        if(i==grid.size()-1 && j==grid[0].size()-1)return xr^grid[i][j];

        if(dp[i][j][xr]!=-1)return dp[i][j][xr];

        int val1,val2;
        //move down
        val1=helper(i+1,j,xr^grid[i][j],grid,dp);

        //move right
        val2=helper(i,j+1,xr^grid[i][j],grid,dp);

        return dp[i][j][xr]=min(val1,val2);
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(1024,-1)));
        return helper(0,0,0,grid,dp);
    }
};