class Solution {
public:
    int minsum(set<vector<int>>& mp){
        if(mp.size()==1){
            return 0;
        }
        int prev=-1e9;
        int mini=1e9;
        for(auto it: mp){
            if(prev==it[0])continue;
            mini=min(mini, abs(prev-it[0]));
            prev=it[0];
        }
        if(mini==1e9)return 0;
        else return mini;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        set<vector<int>> mp;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                mp.insert({grid[i][j],i,j});
            }
        }
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1));
        ans[0][0]=minsum(mp);
        for(int i=0;i<=n-k;i++){
            if(i%2==0){
                for(int j=0;j<m-k;j++){
                    for(int it=i;it<i+k;it++){
                        mp.erase({grid[it][j],it,j});
                        mp.insert({grid[it][j+k],it,j+k});
                    }
                    ans[i][j+1]=minsum(mp);
                }
            }
            else{
                for(int j=m-1;j>=k;j--){
                    for(int it=i;it<i+k;it++){
                        mp.erase({grid[it][j],it,j});
                        mp.insert({grid[it][j-k],it,j-k});
                    }
                    ans[i][j-k]=minsum(mp);
                }
            }
            if(i%2==0 && i<n-k){
                for(int it=m-k; it<m;it++){
                    mp.erase({grid[i][it],i,it});
                    mp.insert({grid[i+k][it],i+k,it});
                }
                ans[i+1][m-k]=minsum(mp);
            }
            else if(i<n-k){
                for(int it=0; it<k;it++){
                    mp.erase({grid[i][it],i,it});
                    mp.insert({grid[i+k][it],i+k,it});
                }
                ans[i+1][0]=minsum(mp);
            }
        }

        return ans;
    }
};