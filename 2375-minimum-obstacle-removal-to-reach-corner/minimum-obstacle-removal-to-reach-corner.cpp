class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({0,0,0});

        while(!pq.empty()){
            int d=pq.top()[0];
            int i=pq.top()[1];
            int j=pq.top()[2];
            pq.pop();

            for(auto it: dir){
                int ni=i+it[0], nj=j+it[1];

                if(nj>=0 && nj<m && ni>=0 && ni<n){
                    if(dist[ni][nj]>d+grid[ni][nj]){
                        dist[ni][nj]=d+grid[ni][nj];
                        pq.push({dist[ni][nj],ni,nj});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};