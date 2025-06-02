class Solution {
public:
    void bfs(int n, int m,queue<pair<int,int>>& q, vector<vector<int>>& image, int color, int inic, vector<vector<int>> visited){
        while(!q.empty()){
            int i= q.front().first;
            int j= q.front().second;
            q.pop();
            image[i][j]=color;

            int n1,n2;
            //right
            n1=i,n2=j+1;
            if(n1>=0&& n1<n && n2>=0 && n2<m && visited[n1][n2]!=1&&image[n1][n2]==inic){
                visited[n1][n2]=1;
                q.push({n1,n2});
            }
            //left
            n1=i,n2=j-1;
            if(n1>=0&& n1<n && n2>=0 && n2<m && visited[n1][n2]!=1 &&image[n1][n2]==inic){
                visited[n1][n2]=1;
                q.push({n1,n2});
            }
            //up
            n1=i-1,n2=j;
            if(n1>=0&& n1<n && n2>=0 && n2<m && visited[n1][n2]!=1 &&image[n1][n2]==inic) {
                visited[n1][n2]=1;
                q.push({n1,n2});
            }
            //down
            n1=i+1,n2=j;
            if(n1>=0&& n1<n && n2>=0 && n2<m && visited[n1][n2]!=1 &&image[n1][n2]==inic){
                visited[n1][n2]=1;
                q.push({n1,n2});
            }

        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> visited(n,(vector<int>(m,0)));
        int iniC=image[sr][sc];
        if(image[sr][sc] != color){
            queue<pair<int,int>> q;
            q.push({sr,sc});
            visited[sr][sc]=1;
            bfs(n,m,q,image,color,iniC,visited);
        }
        return image;
    }
};