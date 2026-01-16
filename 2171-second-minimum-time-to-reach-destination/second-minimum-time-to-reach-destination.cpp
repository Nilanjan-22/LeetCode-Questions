class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        vector<vector<int>> dist(n+1,vector<int>(2,1e9));
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        pq.push({0,1});
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                if(dist[it][1]>d+1){
                    pq.push({d+1,it});
                    if(dist[it][0]>=d+1){
                        if(dist[it][0]>d+1)dist[it][1]=dist[it][0];
                        dist[it][0]=d+1;
                    }
                    else dist[it][1]=d+1;
                }
            }
        }
        cout<<dist[n][1]<<" "<<dist[n][0];
        int ans=0;
        for(int i=0;i<dist[n][1];i++){
            int div=ans/change;
            if(div%2==1)ans=change*(div+1);
            ans+=time;
        }
        return ans;
    }
};