class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        vector<vector<int>> cost(n,vector<int>(m,1e9));

        pq.push({0,0,0});
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            int i=pq.top()[1];
            int j=pq.top()[2];
            int c=pq.top()[0];

            pq.pop();
            if(i==n-1 && j==m-1)return c;
            for(int it=0;it<4;it++){
                int ni=i+dir[it][0], nj=j+dir[it][1];

                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    int inc=1;
                    if(it==grid[i][j]-1)inc=0;

                    if(cost[ni][nj]>c+inc){
                        cost[ni][nj]=c+inc;
                        pq.push({c+inc,ni,nj});
                    }
                }
            }
        }

        return -1;
    }
};