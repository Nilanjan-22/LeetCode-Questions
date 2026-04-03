#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    ordered_set st;
    
    int ans(int i, int prev_right, vector<int>& robots, vector<int>& distance, vector<int>& wallsInBetween) {
        if(i >= n) return 0;

        if(dp[i][prev_right] != -1) return dp[i][prev_right];

        int mx = robots[i] + distance[i];
        int mn = robots[i] - distance[i];
        
        // Count walls covered in the strictly between intervals
        int lc = min(wallsInBetween[i], (int)st.order_of_key(robots[i]) - (int)st.order_of_key(mn));
        int rc = min(wallsInBetween[i+1], (int)st.order_of_key(mx + 1) - (int)st.order_of_key(robots[i] + 1));
        
        // take right
        wallsInBetween[i+1] -= rc;
        int val = rc + ans(i + 1, 1, robots, distance, wallsInBetween);
        wallsInBetween[i+1] += rc; // backtrack

        // take left
        wallsInBetween[i] -= lc;
        val = max(val, lc + ans(i + 1, 0, robots, distance, wallsInBetween));
        wallsInBetween[i] += lc; // backtrack
        
        return dp[i][prev_right] = val;
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        for(int x : walls){
            st.insert(x);
        }
        n = robots.size();

        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[robots[i]] = distance[i];
        }
        
        int j = 0;
        int wallsAtRobots = 0;
        for(auto it : mp){
            robots[j] = it.first;
            distance[j] = it.second;
            // Pre-calculate walls sitting exactly on any robot
            if (st.find(robots[j]) != st.end()) {
                wallsAtRobots++;
            }
            j++;
        }

        vector<int> wallsInBetween(n + 1);
        int prev = -1; // Use -1 to safely capture everything from coordinate 0 up

        for(int i = 0; i < n; i++){
            // Exclusive interval: (prev, robots[i])
            wallsInBetween[i] = st.order_of_key(robots[i]) - st.order_of_key(prev + 1);
            prev = robots[i];
        }
        // Walls strictly after the last robot
        wallsInBetween[n] = st.size() - st.order_of_key(prev + 1);
        
        // Initialize 2D DP array
        dp.assign(n, vector<int>(2, -1));
        
        // Return base walls at robots + max additional walls destroyed
        return wallsAtRobots + ans(0, 0, robots, distance, wallsInBetween);
    }
};