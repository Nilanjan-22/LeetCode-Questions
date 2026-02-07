class Solution {
public:
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int n,m;
    int mod=1e9+7;
    long long dfs(int i,int j, vector<vector<int>>& matrix, vector<vector<long long>>& dp){
        if(dp[i][j]!=-1)return dp[i][j];

        long long ans=0;
        for(auto it: dir){
            int ni=i+it.first,nj=j+it.second;
            if(ni>-1 && ni<n && nj>-1 && nj<m && matrix[i][j]<matrix[ni][nj]){
                long long s=dfs(ni,nj,matrix,dp)%mod;
                ans+=1LL+s;
                ans%=mod;
            }
        }
        return dp[i][j]=ans;
    }
    int countPaths(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,-1));
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                    long long s=dfs(i,j,matrix,dp);
                    s%=mod;
                    ans+=s;
                }
                else ans+=dp[i][j];

                ans%=mod;
            }
        }
        ans+=n*m;
        return ans;
    }
};