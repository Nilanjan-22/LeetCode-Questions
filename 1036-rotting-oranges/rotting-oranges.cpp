class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int freshOranges = 0;
        
        // Use a pair instead of a vector to avoid heap allocation overhead
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) freshOranges++;
            }
        }
        
        // Early exit if there are no fresh oranges to begin with
        if(freshOranges == 0) return 0;
        
        int maxTime = 0;
        // Use a basic C-array for fixed directions
        int directions[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        
        while(!q.empty()){
            int size = q.size();
            bool rottedThisMinute = false;
            
            // Process the queue level-by-level (minute-by-minute)
            while(size--){
                auto [i, j] = q.front();
                q.pop();
                
                for(auto& dir : directions){
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1){
                        grid[ni][nj] = 2;
                        freshOranges--;
                        q.push({ni, nj});
                        rottedThisMinute = true; // Track if we actually rotted anything
                    }
                }
            }
            // Only increment time if we successfully rotted adjacent oranges this round
            if(rottedThisMinute) maxTime++; 
        }
        
        return freshOranges == 0 ? maxTime : -1;
    }
};