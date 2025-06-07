class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //use dijkstra
        int e=flights.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<e;i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        queue<vector<int>> pq;
        // i will store {price,node,total stops so far}

        vector<int> price(n,1e9);
        pq.push({0,src,0});
        price[src]=0;
        while(!pq.empty()){
            int node=pq.front()[1];
            int p=pq.front()[0];
            int s=pq.front()[2];

            pq.pop();
            if(s>k)continue;
            for(auto it: adj[node]){
                int v=it.first;
                int c=it.second;
                if(s<=k && price[v]>p+c){
                    price[v]=p+c;
                    pq.push({price[v],v,s+1});
                }
            }
        }
        if(price[dst]==1e9)return -1;
        else return price[dst];
    }
};