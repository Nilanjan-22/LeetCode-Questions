class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    int cols,rows;
    bool dfs(int i,int j, int pi, int pj, vector<vector<char>>& grid , vector<vector<int>>& visited){
        visited[i][j]=1;
        bool reached=false;
        for(auto it: dir){
            int ni=i+it[0], nj=j+it[1];
            if(nj>=0 && nj<cols && ni>=0 && ni<rows && (nj!=pj || ni!=pi) && grid[i][j]==grid[ni][nj]){
                if(visited[ni][nj]==1)reached=true;
                else reached=reached| dfs(ni,nj,i,j,grid,visited);
            }
        }
        return reached;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        cols=grid[0].size(),rows=grid.size();

        vector<vector<int>> visited(rows,vector<int>(cols,0));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j]){
                    if(dfs(i,j,-1,-1,grid,visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};