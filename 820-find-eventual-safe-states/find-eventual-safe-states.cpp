class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> in(n);
        vector<int> outDeg(n);
        for(int i=0;i<n;i++){
            outDeg[i]=graph[i].size();
            for(auto it: graph[i])in[it].push_back(i);
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(outDeg[i]==0)q.push(i);
        }

        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it: in[node]){
                outDeg[it]--;
                if(outDeg[it]==0)q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};