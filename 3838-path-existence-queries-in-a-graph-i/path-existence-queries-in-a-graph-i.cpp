class Solution {
public:
    class DSU {
        private:
        vector<int> par;
        vector<int> size;

        public: 
        DSU(int n){
            par.resize(n);
            for(int i=0;i<n;i++)par[i]=i;
            size.resize(n,1);
        }

        int getParent(int node){
            if(par[node]==node)return node;
            par[node]=getParent(par[node]);
            return par[node];
        }
        bool checkConnected(int n1, int n2){
            int p1=getParent(n1),p2=getParent(n2);
            return p1==p2;
        }
        void join(int n1, int n2){
            int p1=getParent(n1),p2=getParent(n2);
            if(p1==p2)return;
            if(size[p1]>size[p2]){
                par[p2]=p1;
                size[p1]+=size[p2];
            }
            else {
                par[p1]=p2;
                size[p2]+=size[p1];
            }
        }
    };
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> graphNodes(n);
        for(int i=0;i<n;i++){
            graphNodes[i]={nums[i],i};
        }
        sort(graphNodes.begin(),graphNodes.end());
        DSU dsu = DSU(n);
        for(int i=0;i<n;i++){
            bool finish=false;
            for(int j=i+1;j<n;j++){
                if(graphNodes[j].first-graphNodes[i].first<=maxDiff){
                    int n1=graphNodes[i].second, n2=graphNodes[j].second;
                    dsu.join(n1,n2);
                    if(j==n-1)finish=true;
                }
                else{
                    i=max(i,j-2);
                    break;
                }
            }
            if(finish)break;
        }

        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            int n1=queries[i][0], n2=queries[i][1];
            if(dsu.checkConnected(n1,n2))ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;

    }
};