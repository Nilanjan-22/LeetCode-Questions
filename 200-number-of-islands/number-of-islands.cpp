class Solution {
public:
    vector<vector<int>> dir ={{0,1}, {0,-1} ,{-1,0}, {1,0}};
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        int n=grid.size(), m=grid[0].size();
        if(visited[i][j])return;
        visited[i][j]=true;

        for(vector<int>& v:dir){
            int i1=i+v[0], j1=j+v[1];

            if(i1>n-1 || j1>m-1 || i1<0 || j1<0)continue;
            else if(grid[i1][j1]=='0')continue;
            else{
                dfs(i1,j1,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    cnt++;
                    dfs(i,j,grid,visited);
                }
            }
        }

        return cnt;
    }
};