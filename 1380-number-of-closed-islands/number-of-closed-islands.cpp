class Solution {
public:
    vector<pair<int,int>> dir = {{0,-1},{-1,0},{1,0},{0,1}};
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[i][j]=1;
        for(auto it: dir){
            int ni=i+it.first, nj=j+it.second;
            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]==0 && !vis[ni][nj]){
                dfs(ni,nj,grid,vis);
            }
        }
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            if(grid[0][j]==0 && vis[0][j]==0){
                dfs(0,j,grid,vis);
            }
            if(grid[n-1][j]==0 && vis[n-1][j]==0){
                dfs(n-1,j,grid,vis);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0]==0 && vis[i][0]==0){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]==0 && vis[i][m-1]==0){
                dfs(i,m-1,grid,vis);
            }
        }


        int totalClosedIslands=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                    dfs(i,j,grid,vis);
                    totalClosedIslands++;
                }
            }
        }
        return totalClosedIslands;
    }
};