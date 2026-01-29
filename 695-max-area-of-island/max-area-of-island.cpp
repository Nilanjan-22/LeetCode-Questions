class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int n,m;
    int bfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int cnt=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            int r=q.front().first,c=q.front().second;
            q.pop();
            cnt++;

            for(auto it: dir){
                int nr=it.first,nc=it.second;
                if(r+nr>-1 && r+nr<n && c+nc>-1 && c+nc<m && !vis[r+nr][c+nc] && grid[r+nr][c+nc]==1){
                    vis[r+nr][c+nc]=1;
                    q.push({r+nr,c+nc});
                }
            }

        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<int,int>> q;
        int max_area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    max_area=max(max_area,bfs(i,j,vis,grid));
                }
            }
        }
        return max_area;
    }
};