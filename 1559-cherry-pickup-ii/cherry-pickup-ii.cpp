class Solution {
public:
    int solve(int row, int col1,int col2, vector<vector<int>>&grid, vector<vector<vector<int>>>& dp){
        if(col1>=grid[0].size() || col2>=grid[0].size() || col1<0 || col2<0 || row>=grid.size())return 0;

        if(dp[row][col1][col2]!=-1)return dp[row][col1][col2];

        int collectedCherry=grid[row][col1];
        if(col1!=col2)collectedCherry+=grid[row][col2];

        int maxPicked=0;
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                maxPicked=max(maxPicked,collectedCherry+solve(row+1,col1+i,col2+j,grid,dp));
            }
        }

        return dp[row][col1][col2]=maxPicked;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

        return solve(0,0,m-1,grid,dp);
    }
};