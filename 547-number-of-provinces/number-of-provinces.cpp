class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it])dfs(it,adj,vis);
        }
    }
    void bfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        queue<int> q;
        q.push(node);
        vis[node]=1;

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto it: adj[u]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i)continue;
                else if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                bfs(i,adj,vis);
            }
        }
        return ans;

    }
};