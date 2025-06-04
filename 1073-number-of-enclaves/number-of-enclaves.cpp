class Solution {
public:
    int bfs(int n, int m,queue<pair<int,int>>& q, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int ans=0;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;

            q.pop();
            ans++;

            int sr,sc;
            //left
            sr=i,sc=j-1;
            if(sr>=0 && sr<n && sc>=0 && sc<m && vis[sr][sc]==0 && grid[sr][sc]==1){
                vis[sr][sc]=1;
                q.push({sr,sc});
            }
            //right
            sr=i,sc=j+1;
            if(sr>=0 && sr<n && sc>=0 && sc<m && vis[sr][sc]==0 && grid[sr][sc]==1){
                vis[sr][sc]=1;
                q.push({sr,sc});
            }
            //up
            sr=i-1,sc=j;
            if(sr>=0 && sr<n && sc>=0 && sc<m && vis[sr][sc]==0 && grid[sr][sc]==1){
                vis[sr][sc]=1;
                q.push({sr,sc});
            }
            //down
            sr=i+1,sc=j;
            if(sr>=0 && sr<n && sc>=0 && sc<m && vis[sr][sc]==0 && grid[sr][sc]==1){
                vis[sr][sc]=1;
                q.push({sr,sc});
            }
        }
        return ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)cnt++;
            }
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                vis[0][j]=1;
                q.push({0,j});
            }
        }
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                vis[n-1][j]=1;
                q.push({n-1,j});
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                vis[i][0]=1;
                q.push({i,0});
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }

        return cnt-bfs(n,m,q,vis,grid);
        
    }
};