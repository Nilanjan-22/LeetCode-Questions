class Solution {
public:
    class DSU {
        vector<int> size_array;
        vector<int> parent;
    public:
        DSU(int n){
            size_array.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }

        int find_ulp(int node){
            if(node==parent[node])return node;
            return parent[node]=find_ulp(parent[node]);
        }

        void connect(int node1, int node2){
            int ulp1=find_ulp(node1);
            int ulp2=find_ulp(node2);
            if(ulp1==ulp2)return;
            if(size_array[ulp1]>size_array[ulp2]){
                size_array[ulp1]+=size_array[ulp2];
                parent[ulp2]=ulp1;
            }
            else{
                size_array[ulp2]+=size_array[ulp1];
                parent[ulp1]=ulp2;
            }
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
        DSU ds(n+1);
        int ans=-1;
        for(int i=0;i<n;i++){
            int u=edges[i][0],v=edges[i][1];
            if(ds.find_ulp(u)==ds.find_ulp(v)){
                ans=i;
            }
            else{
                ds.connect(u,v);
            }
        }
        return {edges[ans][0],edges[ans][1]};
    }
};