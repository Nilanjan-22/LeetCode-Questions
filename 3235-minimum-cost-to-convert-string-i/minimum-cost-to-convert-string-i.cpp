class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<map<int,int>> adj(26);
        for(int i=0;i<original.size();i++){
            int u = original[i]-'a';
            int v= changed[i]-'a';
            int c=cost[i];
            if(adj[u].find(v)==adj[u].end() || adj[u][v]>c){
                adj[u][v]=c;
            }
        }

        long long ans=0;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        vector<vector<int>> costv(26,vector<int>(26,1e9));
        for(int i=0;i<26;i++){
            costv[i][i]=0;
            pq.push({0,i});

            while(!pq.empty()){
                int u=pq.top()[1];
                int c=pq.top()[0];
                pq.pop();
                for(auto it: adj[u]){
                    if(costv[i][it.first]>c+it.second){
                        pq.push({it.second+c,it.first});
                        costv[i][it.first]=c+it.second;
                    }
                }
            }
            pq={};
        }
        for(int i=0;i<target.size();i++){
            int u=source[i]-'a', v=target[i]-'a';
            if(costv[u][v]==1e9)return -1;
            else ans+=costv[u][v];
        }

        return ans;
    }
};