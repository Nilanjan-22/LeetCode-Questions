class Solution {
public:
    bool dfs(int node,int col, vector<vector<int>>& adj , vector<int>& color){
        bool isBipartite = true;
        color[node]=col;

        for(auto it: adj[node]){
            if(color[it]==col)return false;
            else if(color[it]==-1){
                isBipartite &= dfs(it,!col,adj,color);
                if(!isBipartite)return false;
            }
        }
        return isBipartite;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        bool bipartite=true;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                bipartite&=dfs(i,1,graph,color);
                if(!bipartite)return false;
            }
        }
        return bipartite;
    }
};