class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        if(n==1 || n==0)return 0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1] , w=edges[i][2];
            adj[u].push_back({v,w});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0,0,1}); //d,node,cnt
        vector<vector<int>> dist(n,vector<int>(k+1,INT_MAX));
        while(!pq.empty()){
            vector<int> temp = pq.top();
            pq.pop();

            int d=temp[0], node = temp[1], cnt=temp[2];
            int prevChar = labels[node]-'a';

            for(auto it: adj[node]){
                int v = it.first, w=it.second;
                int ncnt = cnt+1;
                if(prevChar != labels[v]-'a')ncnt=1;

                if(ncnt<=k && dist[v][ncnt]> d+w){
                    dist[v][ncnt]=d+w;
                    pq.push({d+w,v,ncnt});
                }
            }
        }

        int minDist = INT_MAX;
        for(int i=0;i<=k;i++){
            // cout<<dist[n-1][i]<<" ";
            minDist = min(minDist, dist[n-1][i]);
        }

        if(minDist==INT_MAX)return -1;
        return minDist;


    }
};