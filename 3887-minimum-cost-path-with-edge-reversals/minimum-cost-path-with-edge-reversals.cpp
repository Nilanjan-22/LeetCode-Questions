class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1],w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dist(n,1e9);
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            int w=pq.top().first;
            int v=pq.top().second;
            pq.pop();
            for(auto it: adj[v]){
                if(it.second+w<dist[it.first]){
                    dist[it.first]=it.second+w;
                    pq.push({it.second+w,it.first});
                }
            }
        }
        if(dist[n-1]==1e9)return -1;
        return dist[n-1];
    }
};