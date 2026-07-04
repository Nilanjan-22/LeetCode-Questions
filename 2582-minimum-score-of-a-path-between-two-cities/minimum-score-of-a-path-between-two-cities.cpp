class Solution {
public:
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0],  v=roads[i][1], dist=roads[i][2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({INT_MAX,1});
        vector<int> minValueToNode(n+1,INT_MAX);
        
        while(!pq.empty()){
            int minVal=pq.top().first;
            int u=pq.top().second;
            pq.pop();

            if(minVal>minValueToNode[u])continue;
            for(auto it: adj[u]){
                int nmin=min(minVal,it.second);
                if(minValueToNode[it.first]>nmin){
                    pq.push({nmin,it.first});
                    minValueToNode[it.first]=nmin;
                }
            }
        }

        return minValueToNode[n];

    }
};