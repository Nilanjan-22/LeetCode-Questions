class Solution {
public:
    void dfs(int i, vector<int>& pathVis, vector<int>& vis, vector<vector<int>>& graph){
        // if(pathVis[i]==1){
        //     // vis[i]=1;
        //     return;
        // }
        vis[i]=0;
        pathVis[i]=1;
        for(auto it:graph[i]){
            if(vis[it]==1){
                vis[i]=1;
            }
            if(pathVis[it]==1){
                vis[i]=1;
            }
            else if(vis[it]==-1){
                dfs(it,pathVis,vis,graph);
                if(pathVis[it]==1)vis[it]=1;
                if(vis[it]==1)vis[i]=1;
            }
        }
        pathVis[i]=0;
        return;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        vector<int>pathVis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                dfs(i,pathVis,vis,graph);
            }
        }
        vector<int> safe;
        for(int i=0;i<n;i++){
            if(vis[i]==0)safe.push_back(i);
        }
        return safe;
    }
};