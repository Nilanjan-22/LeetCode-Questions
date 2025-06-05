class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int>inDeg(numCourses);
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i])inDeg[it]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDeg[i]==0)q.push(i);
        }

        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();

            for(auto it: adj[node]){
                inDeg[it]--;
                if(inDeg[it]==0)q.push(it);
            }
        }

        if(topo.size()!=numCourses)return {};
        reverse(topo.begin(),topo.end());
        return topo;
    }
};