class Solution {
public:
    bool check(vector<vector<pair<int,int>>>& adj, long long mid, long long k, int n){
        vector<long long> dis(n,LLONG_MAX);

        priority_queue<pair<long long,int>, vector<pair<long long,int>> , greater<pair<long long,int>>> q;
        q.push({0,0});
        dis[0]=0;
        while(!q.empty()){
            int u=q.top().second;
            long long cost=q.top().first;
            if(u==n-1)return true;
            q.pop();
            if(cost>dis[u])continue;

            for(auto it: adj[u]){
                if(dis[it.first]>cost+it.second && it.second>=mid && cost+it.second<=k){
                    q.push({cost+it.second, it.first});
                    dis[it.first]=cost+it.second;
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1], c=edges[i][2];
            if(online[u]==false || online[v]==false)continue;
            
            adj[u].push_back({v,c});
        }
        long long low=0, high=1e9;
        long long ans=-1;
        while(low<=high){
            long long mid=(low+high)/2LL;
            if(check(adj,mid,k,n)){
                low=mid+1;
                ans=max(ans,mid);
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};