class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph, vector<int>& color,int col){
        bool val=true;
        if(color[i]==col)return false;
        if(color[i]==-1){
            if(col==1)color[i]=0;
            else color[i]=1;
            for(auto it:graph[i]){
                val = val&&dfs(it,graph,color,color[i]);
                if(!val)return false;
            }
        }
        return val;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        bool val=true;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                val= val&& dfs(i, graph, color, 1);
                if(!val)return false;
            }
        }
        return val;
    }
};