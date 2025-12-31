class Solution {
public:
    vector<vector<int>> land;
    vector<int> dr={-1,1,0,0};
    vector<int> dc= {0, 0, -1, 1};
    void change_land(int first,int last, vector<vector<int>>& cells){
        if(first>last){
            for(int i=first; i>last; i--){
                int r=cells[i][0]-1;
                int c=cells[i][1]-1;
                land[r][c]=0;
            }
        }
        else{
            for(int i=first+1;i<=last;i++){
                int r=cells[i][0]-1;
                int c=cells[i][1]-1;
                land[r][c]=1;
            }
        }
    }
    // bool pos(int r, int c, vector<vector<int>>& dp){
    //     if(r>=dp.size() || c>=dp[0].size() || c<0 || r<0)return false;
    //     if(r==dp.size()-1 && land[r][c]==0)return true;

    //     if(dp[r][c]!=-1)return dp[r][c];
    //     if(land[r][c]==1) return dp[r][c]=0;

    //     vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    //     int ans=0;
    //     for(auto d: dir){
    //         ans|=pos(r+d[0],c+d[1], dp);
    //         if(ans)break;
    //     }
    //     return return dp[r][c]=ans;
    // }
    bool dfs(int r, int c, int rows, int cols, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    if (r == rows - 1) {
        // Reached the bottom row
        return true;
    }

    visited[r][c] = true;

    // Explore neighbors
    for (int i = 0; i < 4; ++i) {
        int newR = r + dr[i];
        int newC = c + dc[i];

        if (newR >= 0 && newR < rows && newC >= 0 && newC < cols && 
            grid[newR][newC] == 0 && !visited[newR][newC]) {
            if (dfs(newR, newC,rows, cols, grid, visited)) {
                return true;
            }
        }
    }

    return false;
}

// Main function to check reachability from top to bottom
bool canReachBottom(int rows, int cols, vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return false;
    rows = grid.size();
    cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Start DFS from any accessible cell in the top row
    for (int c = 0; c < cols; ++c) {
        if (grid[0][c] == 0 && !visited[0][c]) {
            if (dfs(0, c, rows, cols, grid, visited)) {
                return true;
            }
        }
    }

    return false;
}
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        land.resize(row,vector<int>(col,0));

        int low=0, high=cells.size()-1,prev=-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            change_land(prev,mid,cells);
            prev=mid;
            if(canReachBottom(row,col,land)){
                low=mid+1;
                ans=mid;
            }
            else {
                high=mid-1;
            }
        }
        return ans+1;

    }
};