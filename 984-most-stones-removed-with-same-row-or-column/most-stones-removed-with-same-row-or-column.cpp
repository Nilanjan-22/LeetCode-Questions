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
    int removeStones(vector<vector<int>>& stones) {
        int maxr=0, maxc=0;
        int e=stones.size();
        for(int i=0;i<e;i++){
            maxr=max(maxr,stones[i][0]);
            maxc=max(maxc,stones[i][1]);
        }

        int n=maxc+maxr+1;
        DisjointSet ds(n);

        for(int i=0;i<e;i++){
            int u=stones[i][0];
            int v=stones[i][1]+maxr+1;

            if(!ds.find(u,v)){
                ds.unionBySize(u,v);
            }
        }
        int cnt=0;
        for(int i=0;i<=n;i++){
            if(ds.parent[i]==i && ds.size[i]!=1)cnt++;
        }
        return e-cnt;

    }
};