class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> points_reached;
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        points_reached.push({0,0});
        visited[0][0]=true;

        map<int,vector<pair<int,int>>> movements;
        movements[1]={{0,-1},{0,1}};
        movements[2]={{1,0},{-1,0}};
        movements[3]={{0,-1},{1,0}};
        movements[4]={{0,1},{1,0}};
        movements[5]={{0,-1},{-1,0}};
        movements[6]={{0,1},{-1,0}};

        map<pair<int,int>,set<int>> move_next;
        move_next[{0,1}]={1,3,5};
        move_next[{0,-1}]={1,4,6};
        move_next[{1,0}]={2,5,6};
        move_next[{-1,0}]={2,3,4};


        while(!points_reached.empty()){
            int x=points_reached.front().first;
            int y=points_reached.front().second;
            if(x==n-1 && y==m-1)return true;
            points_reached.pop();
            int movement_type=grid[x][y];
            for(auto it: movements[movement_type]){
                int nx=x+it.first,ny=y+it.second;
                if(nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==false && move_next[it].find(grid[nx][ny])!=move_next[it].end()){
                    visited[nx][ny]=true;
                    points_reached.push({nx,ny});
                }
            }
        }
        return false;
    }
};