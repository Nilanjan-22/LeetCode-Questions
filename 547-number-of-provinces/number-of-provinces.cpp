class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(isConnected[i][j]==1)adj[i].push_back(j);
            }
        }
        int province=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]!=1){
                visited[i]=1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(visited[it]!=1){
                            q.push(it);
                            visited[it]=1;
                        }
                    }
                }
                province++;
            }

        }
        return province;
    }
};