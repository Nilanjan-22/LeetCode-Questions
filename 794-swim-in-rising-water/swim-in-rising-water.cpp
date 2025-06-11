class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // solving using dijkstra
        int n=grid.size();
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        pq.push({grid[0][0],{0,0}}); // max, i,j
        vector<vector<int>> ans(n, vector<int>(n,1e5));
        ans[0][0]=grid[0][0];
        while(!pq.empty()){
            auto it = pq.top();
            int maxi=it.first;
            int i=it.second.first;
            int j=it.second.second;
            pq.pop();

            if(i==n-1 && j==n-1)return maxi;
            for(auto d:dir){
                int nx=i+d[0],ny=j+d[1];
                if(nx>=n || nx<0 || ny<0 || ny>=n || ans[nx][ny]<=maxi)continue;
                else{
                    ans[nx][ny]=max(maxi,grid[nx][ny]);
                    pq.push({ans[nx][ny],{nx,ny}});
                }
            }
        }
        return -1;
    }
};