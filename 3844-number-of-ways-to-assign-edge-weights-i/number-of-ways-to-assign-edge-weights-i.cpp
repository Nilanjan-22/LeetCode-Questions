class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> combinedEdges(n+2);
        for(auto it: edges){
            combinedEdges[it[0]].push_back(it[1]);
            combinedEdges[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+2,0);
        queue<pair<int,int>> q;
        int maxLevel=0;
        q.push({1,0});
        vis[1]=1;
        while(!q.empty()){
            int node=q.front().first;
            int lvl=q.front().second;
            maxLevel=max(lvl,maxLevel);
            q.pop();
            for(auto it: combinedEdges[node]){
                if(vis[it]==0){
                    q.push({it,lvl+1});
                    vis[it]=1;
                }
            }
        }
        long long ans=1;
        int m=1e9+7;
        for(int i=0;i<maxLevel-1;i++){
            ans*=2;
            ans%=m;
        }
        
        return ans;
    }
};