class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N=numCourses;
        vector<vector<int>> adj(N);
        vector<int> indeg(N);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            indeg[v]++;
            adj[u].push_back(v);
        }
        
        vector<int> toposort;
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            toposort.push_back(u);
            q.pop();
            
            for(auto it: adj[u]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
        return toposort.size()==N;
    }
};