class Solution {
public:
    int n,m,cnt=0;
    queue<vector<int>> q;
    vector<vector<int>> g;
    int bfs(){
        int ans=0,c=0;
        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            int d=q.front()[2];

            ans=max(d,ans);
            q.pop();
            //up
            if(i-1>-1 && g[i-1][j]==1){
                c++;
                g[i-1][j]=2;
                q.push({i-1,j,d+1});
            }
            //down
            if(i+1<n && g[i+1][j]==1){
                c++;
                g[i+1][j]=2;
                q.push({i+1,j,d+1});
            }

            //left
            if(j-1>-1 && g[i][j-1]==1){
                c++;
                g[i][j-1]=2;
                q.push({i,j-1,d+1});
            }
            //right
            if(j+1<m && g[i][j+1]==1){
                c++;
                g[i][j+1]=2;
                q.push({i,j+1,d+1});
            }
            
        }

        if(c==cnt)return ans;
        else return -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        g=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==2)q.push({i,j,0});
                else if(g[i][j]==1)cnt++;
            }
        }

        return bfs();

    }
};