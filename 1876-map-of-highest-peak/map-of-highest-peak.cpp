class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(), m=isWater[0].size();
        queue<vector<int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans (n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            int d=q.front()[2];

            q.pop();

            //up
            if(i-1>-1 && !vis[i-1][j]){
                vis[i-1][j]=1;
                q.push({i-1,j,d+1});
                ans[i-1][j]=d+1;
            }
            //down
            if(i+1<n && !vis[i+1][j]){
                vis[i+1][j]=1;
                q.push({i+1,j,d+1});
                ans[i+1][j]=d+1;
            }
            //right
            if(j+1<m && !vis[i][j+1]){
                vis[i][j+1]=1;
                q.push({i,j+1,d+1});
                ans[i][j+1]=d+1;
            }
            //left
            if(j-1>-1 && !vis[i][j-1]){
                vis[i][j-1]=1;
                q.push({i,j-1,d+1});
                ans[i][j-1]=d+1;
            }
        }

        return ans;
    }
};