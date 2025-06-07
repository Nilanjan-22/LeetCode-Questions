class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //normal dijlstra 
        int e=times.size();
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<e;i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> mint(n+1,1e9);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0,k});
        mint[k]=0;
        while(!pq.empty()){
            int t=pq.top()[0];
            int node = pq.top()[1];

            pq.pop();
            for(auto it: adj[node]){
                int v=it.first;
                int tt=it.second;
                if(mint[v]>t+tt){
                    mint[v]=t+tt;
                    pq.push({mint[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,mint[i]);
        }
        if(ans==1e9)return -1;
        else return ans;
    }
};