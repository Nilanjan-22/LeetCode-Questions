class Solution {
public:
    vector<int> x={0,0,-1,1};
    vector<int> y={-1,1,0,0};
    bool dfs(int i, int j, int max, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int n=grid.size();
        if(i>=n || j>=n || i<0 || j<0 || max<grid[i][j] || vis[i][j]==1)return false;
        if(i==n-1 && j==n-1 && max>=grid[i][j])return true;
        vis[i][j]=1;
        bool ans=false;
        for(int it=0;it<4;it++){
            int x1=i+x[it], y1=j+y[it];
            ans|=dfs(x1,y1,max,vis,grid);
            if(ans==true)return ans;
        }
        return ans;
    }
    int swimInWater(vector<vector<int>>& grid) {
        // use dfs and binary search on ans
        int low=0,high=2500;
        int ans=0;
        int n=grid.size();
        while(low<=high){
            int mid=(low+high)/2;
            vector<vector<int>> vis(n,vector<int>(n,0));
            if(dfs(0,0,mid,vis,grid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            // vis.clear();
        }
        return ans;
    }
};