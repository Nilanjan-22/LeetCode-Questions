class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int e=roads.size();
        long long mod=1e9+7;
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<e;i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<pair<long long,long long>> time(n,{LLONG_MAX,0});
        pq.push({0,0});
        time[0]={0,1};

        while(!pq.empty()){
            int node = pq.top().second;
            long long t= pq.top().first;
            pq.pop();

            for(auto it: adj[node]){
                int v=it.first;
                long long tt=it.second;
                long long p=time[node].second%mod;
                if(time[v].first>t+tt){
                    time[v]={(t+tt),p};
                    pq.push({time[v].first,v});
                }
                else if(time[v].first==t+tt){
                    time[v].second%=mod;
                    time[v].second=(time[v].second+p)%mod;
                }
            }
        }
        return time[n-1].second;


    }
};