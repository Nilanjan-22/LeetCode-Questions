class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<set<int>> preq(numCourses);
        vector<int> indeg(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            indeg[v]++;
            adj[u].push_back(v);
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)q.push(i);
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto it: adj[u]){
                indeg[it]--;
                preq[it].insert(preq[u].begin(),preq[u].end());
                preq[it].insert(u);

                if(indeg[it]==0)q.push(it);
            }
        }
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if(preq[v].find(u)!=preq[v].end())ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};