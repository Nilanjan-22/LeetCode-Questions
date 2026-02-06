class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1))); //mouse pos,cat pos,turn
        //1 denotes cat and 0 denotes mouse
        map<vector<int>,int> mps;
        queue<vector<int>> q;
        for(int i=1;i<n;i++){
            dp[i][i][0]=1;
            dp[i][i][1]=1;
            dp[0][i][1]=0;
            q.push({i,i,0});
            q.push({i,i,1});
            q.push({0,i,1});
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                mps[{i,j,1}]=graph[j].size();
                mps[{i,j,0}]=graph[i].size();
            }
        }
        for(auto it: graph[0]){
            for(int i=1;i<n;i++){
                mps[{i,it,1}]--;
            }
        }

        while(!q.empty()){
            vector<int> v=q.front();
            int mp=v[0],cp=v[1],t=v[2];
            int w=dp[mp][cp][t];
            q.pop();
            
            if(t==1){
                for(auto it: graph[mp]){
                    if(dp[it][cp][0]==-1 && ((w==0)||(--mps[{it,cp,0}]==0))){
                        dp[it][cp][0]=w;
                        q.push({it,cp,0});
                    }
                }
            }
            else{
                for(auto it: graph[cp]){
                    if(it==0)continue;
                    if(dp[mp][it][1]==-1 &&((w==1)||(--mps[{mp,it,1}]==0))){
                        dp[mp][it][1]=w;
                        q.push({mp,it,1});
                    }
                }
            }
        }
        return dp[1][2][0]+1;


    }
};