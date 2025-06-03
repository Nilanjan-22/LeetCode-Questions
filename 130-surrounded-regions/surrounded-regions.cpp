class Solution {
public:
    bool dfsHelp(int i, int j,vector<vector<int>>& vis, vector<vector<char>>& b){
        if(i>=b.size() || i<0 || j>=b[0].size() || j<0)return false;
        if(b[i][j]=='X' || vis[i][j]==1)return true;
        else if(b[i][j]=='O'){
            vis[i][j]=1;
            bool ans= dfsHelp(i,j+1,vis,b)&&dfsHelp(i,j-1,vis,b)&&dfsHelp(i-1,j,vis,b)&&dfsHelp(i+1,j,vis,b);
            return ans;
        }
        return true;
    }
    void dfsFunc(int i, int j,vector<vector<char>>& b){
        if(i>=b.size() || i<0 || j>=b[0].size() || j<0)return;
        if(b[i][j]=='X')return;
        else {
            b[i][j]='X';
            dfsFunc(i,j+1,b);
            dfsFunc(i,j-1,b);
            dfsFunc(i+1,j,b);
            dfsFunc(i-1,j,b);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<pair<int,int>> dfs_start;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&& vis[i][j]==0){
                    vector<vector<int>> vis1=vis;
                    if(dfsHelp(i, j, vis1,board)) {
                        dfs_start.push_back({i,j});
                        vis=vis1;
                    }
                }
            }
        }
        
        for(int i=0;i<dfs_start.size();i++){
            int sr=dfs_start[i].first;
            int sc=dfs_start[i].second;
            cout<<sr<<" "<<sc<<endl;
            dfsFunc(sr,sc,board);
        }
    }
};