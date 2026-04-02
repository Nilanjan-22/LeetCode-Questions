class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n,m;
    int ans(int i,int j, int k,vector<vector<int>>& coins){
        if(i==n-1 && j==m-1){
            if(k>0)return max(0,coins[i][j]);
            else return coins[i][j];
        }

        if(i>=n || j>=m )return -1e9;

        if(dp[i][j][k]!=INT_MIN)return dp[i][j][k];

        int num=coins[i][j];
        int total= num +max(ans(i+1,j,k,coins),ans(i,j+1,k,coins));
        
        if(num<0 && k>0){
            total=max(total,ans(i+1,j,k-1,coins));
            total=max(total,ans(i,j+1,k-1,coins));
        }

        return dp[i][j][k]=total;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size(),m=coins[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return ans(0,0,2,coins);
    }
};