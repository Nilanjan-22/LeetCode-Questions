// class Solution {
// public:
//     int catMouseGame(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1))); //mouse pos,cat pos,turn
//         //1 denotes cat and 0 denotes mouse
//         map<vector<int>,int> mps;
//         queue<vector<int>> q;
//         for(int i=1;i<n;i++){
//             dp[i][i][0]=1;
//             dp[i][i][1]=1;
//             dp[0][i][1]=0;
//             q.push({i,i,0});
//             q.push({i,i,1});
//             q.push({0,i,1});
//         }
//         for(int i=1;i<n;i++){
//             for(int j=1;j<n;j++){
//                 mps[{i,j,1}]=graph[j].size();
//                 mps[{i,j,0}]=graph[i].size();
//             }
//         }
//         for(auto it: graph[0]){
//             for(int i=1;i<n;i++){
//                 mps[{i,it,1}]--;
//             }
//         }

//         while(!q.empty()){
//             vector<int> v=q.front();
//             int mp=v[0],cp=v[1],t=v[2];
//             int w=dp[mp][cp][t];
//             q.pop();
            
//             if(t==1){
//                 for(auto it: graph[mp]){
//                     if(it==0)continue;
//                     if(dp[mp][it][0]==-1 && ((w==0)||(--mps[{mp,it,0}]==0))){
//                         dp[mp][it][0]=w;
//                         q.push({mp,it,0});
//                     }
//                 }
//             }
//             else{
//                 for(auto it: graph[cp]){
//                     if(cp==0)continue;
//                     if(dp[it][cp][1]==-1 &&((w==1)||(--mps[{it,cp,1}]==0))){
//                         dp[it][cp][1]=w;
//                         q.push({it,cp,1});
//                     }
//                 }
//             }
//         }
//         return dp[1][2][0]+1;


//     }
// };

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();

        // dp[mouse][cat][turn] : -1 = unknown, 0 = mouse win, 1 = cat win
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, -1))
        );

        map<vector<int>, int> mps; // remaining moves
        queue<vector<int>> q;

        // Base cases
        for (int i = 1; i < n; i++) {
            dp[i][i][0] = dp[i][i][1] = 1; // cat catches mouse
            dp[0][i][1] = 0;              // mouse reaches hole

            q.push({i, i, 0});
            q.push({i, i, 1});
            q.push({0, i, 1});
        }

        // Initialize degrees
        for (int m = 1; m < n; m++) {
            for (int c = 1; c < n; c++) {
                mps[{m, c, 0}] = graph[m].size(); // mouse turn
                mps[{m, c, 1}] = graph[c].size(); // cat turn
            }
        }

        // Remove cat -> 0 moves
        for (int nei : graph[0]) {
            for (int m = 1; m < n; m++) {
                mps[{m, nei, 1}]--;
            }
        }

        // Retrograde BFS
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            int m = v[0], c = v[1], t = v[2];
            int w = dp[m][c][t];

            if (t == 1) { 
                // CAT just moved → predecessor was MOUSE move
                for (int pm : graph[m]) {
                    if (dp[pm][c][0] != -1) continue;

                    if (w == 0 || --mps[{pm, c, 0}] == 0) {
                        dp[pm][c][0] = w;
                        q.push({pm, c, 0});
                    }
                }
            } 
            else { 
                // MOUSE just moved → predecessor was CAT move
                for (int pc : graph[c]) {
                    if (pc == 0) continue; // cat cannot enter hole
                    if (dp[m][pc][1] != -1) continue;

                    if (w == 1 || --mps[{m, pc, 1}] == 0) {
                        dp[m][pc][1] = w;
                        q.push({m, pc, 1});
                    }
                }
            }
        }

        // Initial state: mouse at 1, cat at 2, mouse turn
        return dp[1][2][0] + 1;
    }
};
