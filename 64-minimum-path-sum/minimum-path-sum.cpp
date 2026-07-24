class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i>=grid.size() || j>=grid[0].size())return 1e9;
        if(i==grid.size()-1 && j==grid[0].size()-1)return grid[i][j];

        if(dp[i][j]!=-1)return dp[i][j];

        int minSum=INT_MAX;

        minSum=min(minSum, grid[i][j]+solve(i+1,j,grid,dp));

        minSum=min(minSum, grid[i][j]+solve(i,j+1,grid,dp));

        return dp[i][j]=minSum;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,grid,dp);
    }
};