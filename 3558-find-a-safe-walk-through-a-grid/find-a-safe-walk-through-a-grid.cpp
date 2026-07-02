class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        priority_queue<vector<int>> q;
        vis[0][0]=1;
        if(grid[0][0]==0)q.push({health,0,0});
        else q.push({health-1,0,0});

        while(!q.empty()){
            int i=q.top()[1];
            int j=q.top()[2];
            int h=q.top()[0];
            q.pop();
            if(h==0)continue;
            if(i==n-1 && j==m-1)return true;

            for(auto d: dir){
                int ni=i+d.first,nj=j+d.second;
                if(ni>=0 && nj>=0 && ni<n && nj<m && vis[ni][nj]==0){
                    int nh=h-grid[ni][nj];
                    q.push({nh,ni,nj});
                    vis[ni][nj]=1;
                }
            }
        }
        return false;

    }
};