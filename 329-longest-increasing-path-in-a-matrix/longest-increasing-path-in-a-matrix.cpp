class Solution {
public:
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int n,m;
    int dfs(int i,int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[i][j]!=-1)return dp[i][j];

        int ans=1;
        for(auto it: dir){
            int ni=i+it.first,nj=j+it.second;
            if(ni>-1 && ni<n && nj>-1 && nj<m && matrix[i][j]<matrix[ni][nj]){
                ans=max(ans,1+dfs(ni,nj,matrix,dp));
            }
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                    ans=max(dfs(i,j,matrix,dp),ans);
                }
            }
        }
        return ans;
    }
};