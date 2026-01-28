class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        const int INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(m, INF));
        
        dp[n-1][m-1] = 0;
        for(int tele = 0; tele <= k; tele++) {
            for(int i = n-1; i >= 0; i--) {
                for(int j = m-1; j >= 0; j--) {
                    if(i == n-1 && j == m-1) continue;
                    
                    int best = INF;
                    
                    if(j + 1 < m) {
                        best = min(best, dp[i][j+1] + grid[i][j+1]);
                    }
                    
                    if(i + 1 < n) {
                        best = min(best, dp[i+1][j] + grid[i+1][j]);
                    }
                    
                    dp[i][j] = min(dp[i][j], best);
                }
            }
            if(tele < k) {
                vector<int> minCostForValue(10001, INF);
                
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        if(dp[i][j] < INF) {
                            int val = grid[i][j];
                            minCostForValue[val] = min(minCostForValue[val], dp[i][j]);
                        }
                    }
                }
                
                for(int val = 1; val <= 10000; val++) {
                    minCostForValue[val] = min(minCostForValue[val], minCostForValue[val-1]);
                }
                
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        int val = grid[i][j];
                        if(minCostForValue[val] < INF) {
                            dp[i][j] = min(dp[i][j], minCostForValue[val]);
                        }
                    }
                }
            }
        }
        
        return dp[0][0];
    }
};