class Solution {
public:
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool findCycleUsingBFS(int i, int j, vector<vector<char>>& grid, set<pair<int,int>>& vis ){
        char ch = grid[i][j];
        vis.insert({i,j});

        set<pair<int,int>> path;
        queue<pair<int,int>> q;
        q.push({i,j});
        map<pair<int,int>,pair<int,int>> par;
        par[{i,j}]={-1,-1};
        while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
            int i1=node.first, j1=node.second;

            for(auto it: dir){
                int ni=i1+it.first , nj = j1+it.second;
                pair<int,int> curNode = {ni,nj};
                if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]==ch && curNode!=par[{i1,j1}]){
                    if(vis.find({ni,nj})!=vis.end())return true;
                    q.push({ni,nj});
                    vis.insert({ni,nj});
                    par[{ni,nj}]={i1,j1};
                }
            }
        }
        return false;
    }   
    bool findCycleUsingDFS(){
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        set<pair<int,int>> vis;

        bool cycleFound=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis.find({i,j})==vis.end()){
                    cycleFound|=findCycleUsingBFS(i,j,grid,vis);
                    if(cycleFound==true){
                        return true;
                    }
                }   
            }
        }
        return false;
    }
};