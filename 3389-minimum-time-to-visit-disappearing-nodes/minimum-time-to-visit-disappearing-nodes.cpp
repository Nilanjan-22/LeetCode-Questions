class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {

        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int d = edges[i][2];
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        dist[0]=0;
        pq.push({0,0});

        while(!pq.empty()){
            pair<int,int> top = pq.top();
            pq.pop();

            int d = top.first;
            int node  = top.second;
            
            if(d > dist[node])continue;
            if(d>=disappear[node]){
                dist[node]=-1;
                continue;
            }

            for(auto it: adj[node]){
                int nd = it.second;
                int dest = it.first;
                if(dist[dest]>d+nd){
                    pq.push({d+nd,dest});
                    dist[dest]=d+nd;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX)dist[i]=-1;
        }

        return dist;

    }
};