class Solution {
public:
    class DSU{
        public:
        map<pair<int,int>,int> size;
        map<pair<int,int>,pair<int,int>> parent;

        DSU(){
        }

        pair<int,int> find_ulp(pair<int,int> n){
            if(parent.find(n)==parent.end()){
                parent[n]=n;
                size[n]=1;
            }
            if(parent[n]==n)return n;
            return parent[n]=find_ulp(parent[n]);
        }

        void connect(pair<int,int> n1, pair<int,int> n2){
            pair<int,int> u1=find_ulp(n1),u2=find_ulp(n2);
            if(u1==u2)return;
            if(u1.first<u2.first){
                size[u1]+=size[u2];
                parent[u2]=u1;
            }
            else{
                size[u2]+=size[u1];
                parent[u1]=u2;
            }
        }
    };
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        set<pair<int,int>> st;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<hits.size();i++){
            st.insert({hits[i][0],hits[i][1]});
        }
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        DSU ds;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(st.find({i,j})!=st.end() || grid[i][j]==0)continue;
                for(auto it: dir){
                    int ni=i+it.first, nj=j+it.second;
                    if(ni>-1 && ni<n && nj>-1 && nj<m && st.find({ni,nj})==st.end() && grid[ni][nj]==1){
                        pair<int,int> n1={i,j};
                        pair<int,int> n2={ni,nj};
                        ds.connect(n1,n2);
                    }
                }
            }
        }
        vector<int> ans(hits.size(),0);
        set<pair<int,int>> temp;
        for(int i=hits.size()-1; i>=0;i--){
            temp.clear();
            pair<int,int> h={hits[i][0],hits[i][1]};
            if(grid[hits[i][0]][hits[i][1]]==0){
                // cout<<"yes";
                continue;
            }
            int cnt=0;
            bool safe=false;
            if(h.first==0)safe=true;
            for(auto it: dir){
                int ni=h.first+it.first, nj=h.second+it.second;
                if(ni>-1 && ni<n && nj>-1 && nj<m && grid[ni][nj]==1){
                    if(st.find({ni,nj})!=st.end())continue;
                    pair<int,int> u = ds.find_ulp({ni,nj});
                    if(u.first!=0 && temp.find(u)==temp.end())cnt+=ds.size[u];
                    else if(u.first==0) safe=true;
                    temp.insert(u);
                }
            }
            for(auto it: temp){
                ds.connect(h,it);               
            }
            st.erase(h);
            if(safe)ans[i]=cnt;
        }
        return ans;
    }
};