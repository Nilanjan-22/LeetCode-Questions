class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findU(int n){
        if(parent[n]==n)return n;
        return parent[n]=findU(parent[n]);
    }

    void unionBySize(int u,int v){
        int parU=findU(u);
        int parV=findU(v);

        if(parU==parV)return;

        else if(size[parU]>size[parV]){
            parent[parV]=parU;
            size[parU]+=size[parV];
        }
        else {
            parent[parU]=parV;
            size[parV]+=size[parU];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();

        DisjointSet ds(n*n-1);

        // each point is denoted by (x,y)=> x*n + y
        // p= (p/n,p%n)
        vector<int> vis(n*n,0);

        vector<int> dir={-1,1,-n,n};
        int maxSize=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int p=i*n+j;
                if(vis[p]==0 && grid[i][j]==1){
                    vis[p]=1;
                    for(auto it:dir){
                        if(p%n==0 && it==-1)continue;
                        if(p%n==n-1 && it==1)continue;
                        if(p+it>=0 && p+it<n*n && vis[p+it]==1 && ds.findU(p)!=ds.findU(p+it)){
                            ds.unionBySize(p,p+it);
                            int pp1=ds.findU(p);
                            maxSize= max(maxSize, ds.size[pp1]);
                        }
                    }
                }
            }
            
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n*n;i++){
            if(vis[i]==0){
                int k=1;
                for(auto d: dir){
                    if(i%n==0 && d==-1)continue;
                    if(i%n==n-1 && d==1)continue;
                    if(i+d>=0 && i+d<n*n){
                        int pp=ds.findU(i+d);
                        if(vis[i+d]==0 || mp.find(pp)!=mp.end())continue;
                        else {
                            k+=ds.size[pp];
                            mp[pp]=1;
                        }
                    }
                }
                maxSize=max(maxSize, k);
                mp.clear();
            }
        }
        if(maxSize==0)return n*n;
        

        return maxSize;
    }
};