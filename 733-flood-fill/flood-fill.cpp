class Solution {
public:
    vector<vector<int>> photo;
    queue<pair<int,int>> q;
    vector<vector<int>> vis;
    int n,m,paint;
    void bfs(int color){
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;

            q.pop();

            //up
            if(i-1>-1 && photo[i-1][j]==color && !vis[i-1][j]){
                q.push({i-1,j});
                vis[i-1][j]=1;
                photo[i-1][j]=paint;
            }
            //down
            if(i+1<n && photo[i+1][j]==color && !vis[i+1][j]){
                q.push({i+1,j});
                vis[i+1][j]=1;
                photo[i+1][j]=paint;
            }
            //left
            if(j-1>-1 && photo[i][j-1]==color && !vis[i][j-1]){
                q.push({i,j-1});
                vis[i][j-1]=1;
                photo[i][j-1]=paint;
            }
            //right
            if(j+1<m && photo[i][j+1]==color && !vis[i][j+1]){
                q.push({i,j+1});
                vis[i][j+1]=1;
                photo[i][j+1]=paint;
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        photo=image;
        n=image.size();
        m=image[0].size();
        vis.resize(n,vector<int>(m,0));
        paint=color;
        int ini=photo[sr][sc];
        q.push({sr,sc});
        vis[sr][sc]=1;
        photo[sr][sc]=paint;
        bfs(ini);
        return photo;
    }
};