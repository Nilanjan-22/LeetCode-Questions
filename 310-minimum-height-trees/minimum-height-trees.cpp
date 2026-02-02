class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vector<int> indeg(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            indeg[u]++;
            indeg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==1)q.push({i,0});
        }

        vector<int> pos(n);
        int maxi=-1;
        while(!q.empty()){
            int u=q.front().first;
            int p=q.front().second;
            pos[u]=p;
            maxi=max(maxi,p);
            q.pop();
            for(auto it: adj[u]){
                indeg[it]--;
                if(indeg[it]==1)q.push({it,p+1});
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(pos[i]==maxi)ans.push_back(i);
        }
        return ans;

    }
};