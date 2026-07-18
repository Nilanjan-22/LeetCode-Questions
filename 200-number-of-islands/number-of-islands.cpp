class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int i,int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[i][j]=1;

        for(auto it: dir){
            int ni = i+it.first, nj=j+it.second;
            if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && vis[ni][nj]==0 && grid[ni][nj]=='1'){
                dfs(ni,nj,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};