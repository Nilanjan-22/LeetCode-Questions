class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{-1,0},{1,0}};
    void dfs(int i, int j, vector<vector<int>>& heights , vector<vector<bool>>& visited){
        int n=heights.size(), m=heights[0].size();
        if(visited[i][j])return;
        visited[i][j]=true;

        for(vector<int>& v: dir){
            int i1=i+v[0], j1=j+v[1];

            if(i1>n-1 || j1>m-1 || i1<0 || j1<0)continue;
            else if(heights[i1][j1]<heights[i][j]) continue;
            else {
                dfs(i1,j1,heights,visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,false)), atlantic(n,vector<bool>(m,false));

        for(int i=0;i<n;i++)dfs(i,0,heights,pacific);
        for(int j=0;j<m;j++)dfs(0,j,heights,pacific);

        for(int i=0;i<n;i++)dfs(i,m-1,heights,atlantic);
        for(int j=0;j<m;j++)dfs(n-1,j,heights,atlantic);

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]&&atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};