class Solution {
public:
    bool loopFoundDFS(int node, vector<vector<int>>& adj, vector<int>& path, vector<int>& vis){
        vis[node]=1;
        path[node]=1;
        bool foundLoop=false;
        for(auto it: adj[node]){
            if(path[it]==1)return true;
            else if(vis[it]!=1){
                foundLoop|=loopFoundDFS(it,adj,path,vis);
            }
        }
        path[node]=0;
        return foundLoop;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][1], v = prerequisites[i][0];
            adj[u].push_back(v);
        }

        vector<int> path(numCourses,0);
        vector<int> vis(numCourses,0);
        bool loopFound=false;
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                loopFound|=loopFoundDFS(i,adj,path,vis);
                if(loopFound==true)return false;
            }
        }
        return true;
    }
};