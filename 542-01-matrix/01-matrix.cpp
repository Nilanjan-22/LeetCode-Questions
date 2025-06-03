class Solution {
public:
    void bfs(int n, int m,queue<tuple<int,int,int>>& q, vector<vector<int>>& visited, vector<vector<int>>& mat, vector<vector<int>>& dist){
        while(!q.empty()){
            int i=get<0>(q.front());
            int j=get<1>(q.front());
            int d=get<2>(q.front());
            q.pop();

            int n1,n2;
            //left
            n1=i,n2=j-1;
            if(n1>=0 && n1<n && n2>=0 && n2<m && visited[n1][n2]==0){
                visited[n1][n2]=1;
                dist[n1][n2]=d+1;
                q.push({n1,n2,d+1});
            }
            //right
            n1=i,n2=j+1;
            if(n1>=0 && n1<n && n2>=0 && n2<m && visited[n1][n2]==0){
                visited[n1][n2]=1;
                dist[n1][n2]=d+1;
                q.push({n1,n2,d+1});
            }
            //up
            n1=i-1,n2=j;
            if(n1>=0 && n1<n && n2>=0 && n2<m && visited[n1][n2]==0){
                visited[n1][n2]=1;
                dist[n1][n2]=d+1;
                q.push({n1,n2,d+1});
            }
            //down
            n1=i+1,n2=j;
            if(n1>=0 && n1<n && n2>=0 && n2<m && visited[n1][n2]==0){
                visited[n1][n2]=1;
                dist[n1][n2]=d+1;
                q.push({n1,n2,d+1});
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m));
        queue<tuple<int,int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&& mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({i,j,0});
                }
            }
        }
        bfs(n,m,q,vis,mat,dist);
        return dist;
    }
};