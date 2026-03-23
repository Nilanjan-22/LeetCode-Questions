class Solution {
public:
    int mod=1e9+7;
    map<pair<int,int>,pair<long long,long long>> dp;
    int n,m;
    pair<long long,long long> ans(int i,int j, vector<vector<int>>& g){
        if(i==n-1 && j==m-1)return {g[i][j],g[i][j]};

        if(dp.find({i,j})!=dp.end())return dp[{i,j}];

        if(i==n-1){
            pair<long long,long long> p = ans(i,j+1,g);

            long long mx=max(p.first*(long long)g[i][j] , p.second*(long long)g[i][j]);
            long long mn=min(p.first*(long long)g[i][j] , p.second*(long long)g[i][j]);
            return dp[{i,j}]={mx,mn};
        }
        else if(j==m-1){
            pair<long long,long long> p = ans(i+1,j,g);

            long long mx=max(p.first*(long long)g[i][j] , p.second*(long long)g[i][j]);
            long long mn=min(p.first*(long long)g[i][j] , p.second*(long long)g[i][j]);
            return dp[{i,j}]={mx,mn};
        }

        pair<long long,long long> r=ans(i,j+1,g);
        pair<long long,long long> d=ans(i+1,j,g);
        long long mx1=max(r.first*(long long)g[i][j] , r.second*(long long)g[i][j]);
        long long mn1=min(r.first*(long long)g[i][j] , r.second*(long long)g[i][j]);

        long long mx2=max(d.first*(long long)g[i][j] , d.second*(long long)g[i][j]);
        long long mn2=min(d.first*(long long)g[i][j] , d.second*(long long)g[i][j]);

        long long mx=max(mx1,mx2) ,  mn=min(mn1,mn2);

        return dp[{i,j}]={mx,mn};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        long long maxi=(ans(0,0,grid).first)%mod;
        if(maxi<0)return -1;
        else return maxi;
    }
};