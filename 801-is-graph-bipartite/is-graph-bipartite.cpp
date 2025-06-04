class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        queue<pair<int,int>> q; //pair<int,int> => node, color

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                q.push({i,0});
                while(!q.empty()){
                    int node=q.front().first;
                    int col=q.front().second;

                    q.pop();
                    for(auto it:graph[node]){
                        if(color[it]==-1){
                            if(col==0)color[it]=1;
                            else color[it]=0;
                            q.push({it,color[it]});
                        }
                        else if(color[it]==col)return false;
                    }
                }
            }
        }
        return true;
    }
};