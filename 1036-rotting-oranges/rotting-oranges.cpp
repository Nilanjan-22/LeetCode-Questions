class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
        int freshOranges=0;
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j,0});
                if(grid[i][j]==1)freshOranges++;
            }
        }
        int maxTime=0;
        while(!q.empty()){
            int i=q.front()[0],j=q.front()[1],time=q.front()[2];
            maxTime=max(time,maxTime);
            q.pop();

            for(auto dir:directions){
                int ni=i+dir[0],nj=j+dir[1];

                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                    freshOranges--;
                    grid[ni][nj]=2;
                    q.push({ni,nj,time+1});
                }
            }
        }
        if(freshOranges>0)return -1;
        return maxTime;
    }
};