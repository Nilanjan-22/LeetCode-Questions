class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<long long>> pref(n,vector<long long>(m,0)),suff(n,vector<long long>(m,0));
        long long mul=1;
        int mod=12345;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mul*=grid[i][j];
                mul%=mod;
                pref[i][j]=mul;
            }
        }
        mul=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                mul*=grid[i][j];
                mul%=mod;
                suff[i][j]=mul;
            }
        }


        vector<vector<int>> ans(n,vector<int>(m,0));
        if(n==1){
            for(int i=0;i<m;i++){
                if(i==0)ans[0][i]=suff[0][i+1];
                else if(i==m-1)ans[0][i]=pref[0][i-1];
                else {
                    long long t=pref[0][i-1]*suff[0][i+1];
                    t%=mod;
                    ans[0][i]=t;
                }
            }
        }
        else if(m==1){
            for(int i=0;i<n;i++){
                if(i==0)ans[i][0]=suff[i+1][0];
                else if(i==n-1)ans[i][0]=pref[i-1][0];
                else {
                    long long t=pref[i-1][0]*suff[i+1][0];
                    t%=mod;
                    ans[i][0]=t;
                }
            }
        }
        else {
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i==0 && j==0)ans[i][j]=suff[i][j+1];
                    else if(j==m-1 && i==n-1){
                        ans[i][j]=pref[i][j-1];
                    }

                    else if(j==m-1){
                        long long t=pref[i][j-1]*suff[i+1][0];
                        t%=mod;
                        ans[i][j]=t;
                    }
                    else if(j==0){
                        long long t=pref[i-1][m-1]*suff[i][j+1];
                        t%=mod;
                        ans[i][j]=t;
                    }
                    else{
                        long long t=pref[i][j-1]*suff[i][j+1];
                        t%=mod;
                        ans[i][j]=t;
                    }
                }
            }
        }

        return ans;
    }
};