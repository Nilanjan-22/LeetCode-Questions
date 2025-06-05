class Solution {
public:
    bool dfs(int i, stack<int>& st, vector<int>& vis,vector<int>& pathVis, vector<vector<int>>& adj){
        vis[i]=1;
        pathVis[i]=1;
        for(auto it: adj[i]){
            if(vis[it]==0){
                if(dfs(it,st,vis,pathVis,adj))return true;
            }
            else if(pathVis[it]==1)return true;
        }
        st.push(i);
        pathVis[i]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        stack<int> st;
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(dfs(i,st,vis,pathVis,adj))return {};
            }
        }
        int n=st.size();
        vector<int> topo(n);
        for(int i=n-1;i>=0;i--){
            topo[i]=st.top();
            st.pop();
        }
        return topo;
    }
};