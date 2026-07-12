class Solution {
public:
    long long cntPaths(int i, int j, vector<string>& grid, vector<vector<long long>>& dp){
        if(i==grid.size()-1 && j==grid[0].size()-1)return 1;
        if(i>=grid.size() || j>=grid[0].size())return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];

        long long ways=0;
        if(i<grid.size()-1 && grid[i+1][j]=='.')ways+=cntPaths(i+1,j,grid,dp);
        if(j<grid[0].size()-1 && grid[i][j+1]=='.')ways+=cntPaths(i,j+1,grid,dp);

        return dp[i][j]=ways;
    }
    bool pos(vector<string>& grid, int k){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if((i==0 && j==0) ||(i==grid.size()-1 && j==grid[0].size()-1))continue;
                grid[i][j]='#';
                int m=grid.size(),n=grid[0].size();
                vector<vector<long long>> dp(m,vector<long long>(n,-1));
                long long p = cntPaths(0,0,grid,dp);
                if(p==k)return true;
                if(p<k){
                    grid[i][j]='.';
                }
            }
        }
        return false;
    }
    vector<string> createGrid(int m, int n, int k) {
        vector<string> grid (m,string(n,'.'));
        vector<vector<long long>> dp(m,vector<long long>(n,-1));
        long long p = cntPaths(0,0,grid,dp);
        if(p<k)return {};
        if(p==k)return grid;

        if(pos(grid,k)){
            return grid;
        }

        return {};
    }
};