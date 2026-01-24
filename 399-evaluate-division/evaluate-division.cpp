
class Solution {
public:
    map<string,vector<pair<string,double>>> adj;
    map<string,string> parent;
    map<string,int> size;
    class DSU{
        public:
        map<string,vector<pair<string,double>>> ad;
        map<string,string> par;
        map<string,int> si;

        DSU (map<string,vector<pair<string,double>>> adj,map<string,string> parent,map<string,int> size){
            ad=adj;
            par=parent;
            si=size;
        }

        string find_ulp(string node){
            if(par[node]==node)return node;
            return par[node]=find_ulp(par[node]);
        }

        void connect(string n1, string n2, double val){
            if(find_ulp(n1)==find_ulp(n2))return;
            ad[n1].push_back({n2,val});
            ad[n2].push_back({n1,(1.0/val)});
            string ulp1=find_ulp(n1),ulp2=find_ulp(n2);
            if(si[n1]>si[n2]){
                par[ulp2]=ulp1;
                si[ulp1]+=si[ulp2];
            }
            else{
                par[ulp1]=ulp2;
                si[ulp2]+=si[ulp1];
            }
        }
    };
    double dfs(string node,string dest, map<string,int>& vis){
        vis[node]=1;
        double ans=0.0;
        if(node==dest)return 1.0;
        for(auto it: adj[node]){
            string v=it.first;
            double val=it.second;
            if(!vis[v])ans+=val*dfs(v,dest,vis);
        }
        return ans;
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,int> vis;
        for(int i=0;i<equations.size();i++){
            string s1=equations[i][0], s2=equations[i][1];
            if(parent.find(s1)==parent.end()){
                parent[s1]=s1;
                size[s1]=1;
                vis[s1]=0;
            }
            if(parent.find(s2)==parent.end()){
                parent[s2]=s2;
                size[s2]=1;
                vis[s1]=0;
            }
        }
        // for(int i=0;i<queries.size();i++){
        //     string s1=queries[i][0], s2=queries[i][1];
        //     if(parent.find(s1)==parent.end()){
        //         parent[s1]=s1;
        //         size[s1]=1;
        //         vis[s1]=0;
        //     }
        //     if(parent.find(s2)==parent.end()){
        //         parent[s2]=s2;
        //         size[s2]=1;
        //         vis[s1]=0;
        //     }
        // }

        DSU ds(adj,parent,size);

        for(int i=0;i<equations.size();i++){
            string s1=equations[i][0], s2=equations[i][1];

            ds.connect(s1,s2,values[i]);
        }
        adj=ds.ad;
        // answering queries
        int n=queries.size();
        vector<double> ans(n);
        map<string,int> copy;
        for(int i=0;i<n;i++){
            string s1=queries[i][0], s2=queries[i][1];
            if(parent.find(s1)==parent.end() || parent.find(s2)==parent.end() || ds.find_ulp(s1)!=ds.find_ulp(s2))ans[i]=-1.0;
            else{
                copy=vis;
                ans[i]=dfs(s1,s2,copy);
            }
        }

        return ans;

    }
};