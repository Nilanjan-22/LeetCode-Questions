class Solution {
public:
    vector<vector<string>>ans;
    unordered_map<string, int> mp;
    void bfs(unordered_set<string>& st,queue<pair<string,int>>& q,unordered_map<string, int>& mp, string&  ew){
        while(!q.empty()){
            string s=q.front().first;
            int d=q.front().second;
            mp[s]=d;
            q.pop();
            if(s==ew)return;
            for(int i=0;i<s.size();i++){
                string copy=s;
                for(char it='a';it<='z';it++){
                    copy[i]=it;
                    if(st.count(copy)>0){
                        st.erase(copy);
                        q.push({copy,d+1});
                    }
                }
            }
        }
        return;
    }
    void dfs(string& s, vector<string>& seq, string& bw){
        if(s==bw){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        for(int i=0;i<s.size();i++){
            string copy=s;
            for(char it='a';it<='z';it++){
                copy[i]=it;
                if(mp.find(copy)!=mp.end() && mp[copy]+1==mp[s]){
                    seq.push_back(copy);
                    dfs(copy,seq,bw);
                    seq.pop_back();
                }
            }
        }

    }
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wl) {
        unordered_set<string> st;
        queue<pair<string,int>> q;
        for(int i=0;i<wl.size();i++)st.insert(wl[i]);

        st.insert(bw);
        q.push({bw,0});
        st.erase(bw);

        bfs(st,q,mp,ew);

        if(mp.find(ew)!=mp.end()){
            vector<string> seq;
            seq.push_back(ew);
            dfs(ew,seq,bw);
        }
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<" ";
        }
        return ans;
    }
};