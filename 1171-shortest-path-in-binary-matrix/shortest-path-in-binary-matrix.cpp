class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //simply use dijkstra
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> mi={0,0,-1,1,-1,1,-1,1};
        vector<int> mj={-1,1,0,0,1,1,-1,-1};   // all the possible 8 movements

        if(grid[0][0]==1)return -1;

        pq.push({1,0,0});
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        while(!pq.empty()){
            int d=pq.top()[0];
            int i=pq.top()[1];
            int j=pq.top()[2];
            pq.pop();
            for(int it=0;it<8;it++){
                int i1=i+mi[it], j1=j+mj[it];
                if(i1<n && i1>-1 && j1<m && j1>-1 && grid[i1][j1]==0){
                    if(d+1<dist[i1][j1]){
                        dist[i1][j1]=d+1;
                        pq.push({d+1,i1,j1});
                    }
                }
            }

        }
        if(dist[n-1][m-1]==1e9)return -1;
        else return dist[n-1][m-1];

    }
};