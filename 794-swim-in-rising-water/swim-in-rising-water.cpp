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
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);

        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<int> x={-1,1,0,0};
        vector<int> y={0,0,1,-1};
        vector<pair<int,pair<int,int>>> sqs;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sqs.push_back({grid[i][j],{i,j}});
            }
        }
        sort(sqs.begin(),sqs.end());
        for(auto sq : sqs){
            int h=sq.first;
            int i=sq.second.first;
            int j=sq.second.second;

            vis[i][j]=1;
            int p=i*n+j;

            for(int it=0;it<4;it++){
                int nx=i+x[it],ny=j+y[it];

                if(nx>=n || nx<0 || ny<0 || ny>=n || vis[nx][ny]==0)continue;
                else{
                    ds.unionBySize(p, nx*n+ny);
                }
            }
            
            if(ds.U_par(0)== ds.U_par(n*n-1))return h;
        }

        return -1;
        
    }
};