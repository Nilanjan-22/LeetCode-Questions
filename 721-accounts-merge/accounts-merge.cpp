class DisjointSet {
    
public:
    vector<int> rank,size,parent;
    DisjointSet(int n) {
     rank.resize(n+1,0);
     size.resize(n+1,1);
     parent.resize(n+1);
     for(int i=0;i<n+1;i++){
        parent[i]=i;
     }
    }
    int U_par(int n){
        if(parent[n]==n)return n;
        int p=parent[n];
        return parent[n]= U_par(p);
    }

    bool find(int u, int v) {
        if(U_par(u)==U_par(v))return true;
        return false;
    }

    void unionByRank(int u, int v) {
        int upu=U_par(u);
        int upv=U_par(v);

        if(upu==upv)return;
        if(rank[upu]<rank[upv]){
            parent[upu]=upv;
        }
        else if(rank[upv]<rank[upu]){
            parent[upv]=upu;
        }
        else {
            parent[upv]=upu;
            rank[upu]++;
        }
    }

    void unionBySize(int u, int v) {
        int upu=U_par(u);
        int upv=U_par(v);

        if(upu==upv)return;
        if(size[upu]<size[upv]){
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else {
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n-1);

        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string s=accounts[i][j];
                if(mp.find(s)==mp.end()){
                    mp[s]=i;
                }
                else {
                    int p=mp[s];
                    ds.unionBySize(p,i);
                }
            }
        }

        vector<vector<string>> merge(n);
        for(auto it: mp){
            int node=it.second;
            string em=it.first;
            int par=ds.U_par(node);
            merge[par].push_back(em);
        }

        for(int i=0;i<n;i++){
            string name=accounts[i][0];
            sort(merge[i].begin(),merge[i].end());
            merge[i].insert(merge[i].begin(),name);
        }
        
        int del=0;
        for(int i=0;i<n;i++){
            if(merge[i-del].size()==1){
                merge.erase(merge.begin()+i-del);
                del++;
            }
        }

        return merge;

    }
};