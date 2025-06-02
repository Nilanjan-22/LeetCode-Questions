class Solution {
public:
    int bfs(int n, int c, int m ,queue<tuple<int,int,int>>& q, vector<vector<int>>& g){
        int ans=0,cnt=0;
        while(!q.empty()){
            int i=get<0>(q.front());
            int j = get<1>(q.front());
            int t=get<2>(q.front());
            ans=max(ans,t);
            cnt++;
            q.pop();
            int n1,n2;
            //left
            n1=i,n2=j-1;
            if(n1>=0 && n1<n && n2>=0 && n2<m && g[n1][n2]==1){
                g[n1][n2]=2;
                q.push({n1,n2,t+1});
            }
            //right
            n1=i,n2=j+1;
            if(n1>=0 && n1<n && n2>=0 && n2<m && g[n1][n2]==1){
                g[n1][n2]=2;
                q.push({n1,n2,t+1});
            }
            //up
            n1=i-1,n2=j;
            if(n1>=0 && n1<n && n2>=0 && n2<m && g[n1][n2]==1){
                g[n1][n2]=2;
                q.push({n1,n2,t+1});
            }
            //down
            n1=i+1,n2=j;
            if(n1>=0 && n1<n && n2>=0 && n2<m && g[n1][n2]==1){
                g[n1][n2]=2;
                q.push({n1,n2,t+1});
            }
        }
        if(cnt==c)return ans;
        return -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> gCopy=grid;
        queue<tuple<int,int,int>> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                    cnt++;
                }
                else if(grid[i][j]==1)cnt++;
            }
        }
        
        return bfs(n,cnt,m,q,gCopy);

        
    }
};