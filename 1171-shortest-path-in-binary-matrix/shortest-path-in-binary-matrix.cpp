class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //simply use bfs
        int n=grid.size();
        int m=grid[0].size();
        queue<vector<int>> pq;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<int> mi={0,0,-1,1,-1,1,-1,1};
        vector<int> mj={-1,1,0,0,1,1,-1,-1};   // all the possible 8 movements

        if(grid[0][0]==1)return -1;

        pq.push({1,0,0});
        vector<vector<int>> dist(n,vector<int>(m));
        dist[0][0]=1;
        vis[0][0]=1;
        while(!pq.empty()){
            int d=pq.front()[0];
            int i=pq.front()[1];
            int j=pq.front()[2];
            pq.pop();
            for(int it=0;it<8;it++){
                int i1=i+mi[it], j1=j+mj[it];
                if(i1<n && i1>-1 && j1<m && j1>-1 && vis[i1][j1]==0 && grid[i1][j1]==0){
                    dist[i1][j1]=d+1;
                    vis[i1][j1]=1;
                    pq.push({d+1,i1,j1});
                }
            }

        }
        if(vis[n-1][m-1]==0)return -1;
        else return dist[n-1][m-1];

    }
};