class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> outdeg(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<graph.size();i++){
            for(auto it: graph[i])adj[it].push_back(i);

            outdeg[i]=graph[i].size();
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(outdeg[i]==0)q.push(i);
        }

        vector<int> safe;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            safe.push_back(u);
            for(auto it: adj[u]){
                outdeg[it]--;
                if(outdeg[it]==0)q.push(it);
            }
        }

        sort(safe.begin(),safe.end());
        return safe;

    }
};