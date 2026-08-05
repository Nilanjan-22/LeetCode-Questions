class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, set<int>& suspiciousNodes){
        vis[node]=1;
        suspiciousNodes.insert(node);
        for(auto it: adj[node]){
            if(vis[it]==0){
                dfs(it,adj,vis,suspiciousNodes);
            }
        }
    }
    void Countdfs(int node, vector<vector<int>>& adj, vector<int>& vis, int& count){
        vis[node]=1;
        count++;
        for(auto it: adj[node]){
            if(vis[it]==0){
                Countdfs(it,adj,vis,count);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<vector<int>> undirectedAdj(n);
        for(int i=0;i<invocations.size();i++){
            int u=invocations[i][0], v=invocations[i][1];
            adj[u].push_back(v);
            undirectedAdj[u].push_back(v);
            undirectedAdj[v].push_back(u);
        }
        set<int> suspiciousNodes;
        vector<int> vis(n,0);
        dfs(k,adj,vis,suspiciousNodes);
        for(auto &it: vis)it=0;
        int count=0;
        Countdfs(k,undirectedAdj,vis,count);
        vector<int> finalNodes;
        if(count> suspiciousNodes.size()){
            for(int i=0;i<n;i++){
                finalNodes.push_back(i);
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(suspiciousNodes.find(i)==suspiciousNodes.end()){
                    finalNodes.push_back(i);
                }
            }
        }
        return finalNodes;
    }
};