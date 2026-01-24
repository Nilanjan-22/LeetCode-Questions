class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>&adj,int c, int p){
        vis[node]=1;
        for(auto it:adj[node]){
            if(node==p && it==c)continue;
            if(!vis[it]){
                dfs(it,vis,adj,c,p);
            }
        }
    }
    bool check(int node, int n, vector<vector<int>>& adj,int c, int p){
        vector<int> vis(n,0);
        dfs(node,vis,adj,c,p);
        for(int i=1;i<n;i++){
            if(vis[i]==0)return false;
        }
        return true;

    }
    class DSU {
        vector<int> parent;
    public:
        DSU(int n){
            parent.resize(n+1);
            for(int i=0;i<n+1;i++)parent[i]=i;
        }

        int find_ulp(int node){
            if(parent[node]==node)return node;
            return parent[node]=find_ulp(parent[node]);
        }

        void connect(int p, int c){
            int ulp1=find_ulp(p),ulp2=find_ulp(c);
            if(ulp1==ulp2)return;
            else{
                parent[ulp2]=ulp1;
            }
        }
    };
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> par(n+1), adj(n+1);
        for(int i=0;i<n;i++){
            int p=edges[i][0], c=edges[i][1];
            par[c].push_back(p);
            adj[p].push_back(c);
        }
        int root=-1;
        for(int i=1;i<n+1;i++){
            if(par[i].size()==0)root=i;
        }
        int i;
        for(i=1;i<n+1;i++){
            if(par[i].size()>1){
                break;
            }
        }
        if(i<=n && root!=-1){
            int last=-1;
            for(int j=0;j<par[i].size();j++){
                if(check(root,n+1,adj,i,par[i][j])) last=j;
            }
            return {par[i][last],i};
        }
        else{
            DSU ds(n);
            int ans=-1;
            for(int it=0;it<n;it++){
                int p=edges[it][0],c=edges[it][1];
                if(ds.find_ulp(p)==ds.find_ulp(c))ans=it;
                else ds.connect(p,c);
            }
            return {edges[ans][0],edges[ans][1]};
        }
        return {};

    }
};