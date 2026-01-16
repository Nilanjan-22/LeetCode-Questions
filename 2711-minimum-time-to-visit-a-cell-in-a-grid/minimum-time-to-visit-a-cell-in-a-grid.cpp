class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if  (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int n=grid.size(),m=grid[0].size();
        priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            int i=pq.top()[1];
            int j=pq.top()[2];
            int time=pq.top()[0];

            if(i==n-1 && j==m-1)return time;
            pq.pop();

            // bool loop=true;
            // for(auto it: dir){
            //     int ni=i+it[0];
            //     int nj=j+it[1];
            //     if(ni>=0 && nj>=0 && ni<n && nj<m){
            //         if(grid[ni][nj]<=time+1){
            //             loop=true;
            //             break;
            //         }
            //     }
            // }

            for(auto it: dir){
                int ni=i+it[0], nj=j+it[1];
                if(ni>=0 && nj>=0 && ni<n && nj<m && dist[ni][nj]==1e9){
                    // if(!loop && grid[ni][nj]>time+1)continue;
                    
                    int need;
                    int dif=(grid[ni][nj]-time)/2;
                    need=max(2*dif,0);
                    if(dist[ni][nj]>time+need+1){
                        dist[ni][nj]=time+need+1;
                        pq.push({time+need+1,ni,nj});
                    }
                }
            }
        }
        if(dist[n-1][m-1]==1e9)return -1;
        else return dist[n-1][m-1];

    }
};