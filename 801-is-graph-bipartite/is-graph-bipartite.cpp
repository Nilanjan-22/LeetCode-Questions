class Solution {
public:
    vector<int> dist;
    bool dfs(int u,int par,int d, vector<int>& vis, vector<vector<int>>& graph ){
        vis[u]=1;
        dist[u]=d;
        bool val=true;
        for(auto it: graph[u]){
            if(!vis[it]){
                val=val&& dfs(it,u,d+1,vis,graph);
            }
            else if(it!=par && (dist[u]-dist[it])%2==0 ){
                return false;
            }
        }

        return val;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        dist.resize(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                if(!dfs(i,-1,1,vis,graph))return false;
            }
        }
        return true;
    }
};