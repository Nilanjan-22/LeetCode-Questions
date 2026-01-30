class Solution {
public:
    vector<long long> dp;
    int n;
    string s1,s2;
    map<string, set<string>> adj;
    long long ans(int i, string&source , string & target, map<pair<string,string> , long long>& mc){
        // if(i==n)return 0;
        if(i==n)return 0;

        if(dp[i]!=-1)return dp[i];

        long long mini=1e18;
        if(source[i]==target[i])mini=min(mini,ans(i+1,source,target,mc));

        for(auto &it: adj){
            string s1=it.first;
            int l=s1.size();
            if(i+l>n)continue;
            if(source.compare(i,l,s1)!=0)continue;
            for(auto &it2 : it.second){
                int c=mc[{s1,it2}];
                if(target.compare(i,l,it2)!=0)continue;
                mini=min(mini,c+ans(i+l,source,target,mc));
            }
        }
        return dp[i]=mini;

    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        map<pair<string,string>, long long> cost_map;
        for(int i=0;i<original.size();i++){
            string u=original[i],v=changed[i];
            long long c=cost[i];
            if(cost_map.find({u,v})==cost_map.end() || cost_map[{u,v}]>c){
                adj[u].insert(v);
                cost_map[{u,v}]=c;
            }
        }
        priority_queue<pair<long long,string> , vector<pair<long long,string>>, greater<pair<long long , string>>> pq; 
        map<pair<string,string> , long long> mincost;
        for(auto it1: adj){
            string st=it1.first;
            pq={};
            pq.push({0,st});
            mincost[{st,st}]=0;
            while(!pq.empty()){
                string s=pq.top().second;
                long long cs=pq.top().first;
                pq.pop();
                for(auto it: adj[s]){
                    string s1=it;
                    if(cost_map.find({s,s1})==cost_map.end())continue;
                    long long c=cost_map[{s,s1}];
                    if(mincost.find({st,s1})==mincost.end() || mincost[{st,s1}]>cs+c){
                        adj[st].insert(s1);
                        mincost[{st,s1}]=cs+c;
                        pq.push({cs+c,s1});
                    }
                }
            }
        }

        // for(auto it: mincost){
        //     cout<<it.first.first<<"->"<<it.first.second<<" cost="<<it.second<<endl;
        // }
        n=source.size();
        dp.resize(n,-1);
        long long final=ans(0,source,target,mincost);
        if(final>=1e15)return -1;
        return final;
    }
};