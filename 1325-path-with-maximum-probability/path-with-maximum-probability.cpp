class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succProb[i];
            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }

        set<pair<double,int> > pq;
        vector<double> prob(n,0.0);
        prob[start_node]=1.0;
        pq.insert({1.0,start_node});

        while(!pq.empty()){
            double p=(*pq.rbegin()).first;
            int u=(*pq.rbegin()).second;
            pq.erase({p,u});
            for(auto it: adj[u]){
                double p1=it.second;
                int v=it.first;

                if(p1*p>prob[v]){
                    if(prob[v]!=0)pq.erase({prob[v],v});
                    prob[v]=p1*p;
                    pq.insert({prob[v],v});
                }
            }
        }

        return prob[end_node];
    }
};