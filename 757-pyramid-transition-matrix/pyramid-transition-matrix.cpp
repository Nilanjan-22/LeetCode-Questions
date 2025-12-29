class Solution {
public:
    bool ans(string& prev, int i , string& cur , map<pair<char,char>, vector<char>>& mp, set<string>& dp){
        if(prev.size()==1)return true;

        if(i==prev.size()-1){
            if(dp.find(cur)!=dp.end())return false;
            bool ok=ans(cur,0,*(new string()),mp,dp);
            if(ok)return true;
            else {
                dp.insert(cur);
                return false;
            };
        }

        if(mp.find({prev[i],prev[i+1]})==mp.end())return false;
        vector<char> it= mp[{prev[i],prev[i+1]}];
        for(auto c: it){
            cur.push_back(c);
            if(ans(prev,i+1,cur,mp,dp))return true;
            cur.pop_back();
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        string prev=bottom, cur="";
        map<pair<char,char> , vector<char>> mp;
        set<string> dp;
        for(int i=0;i<allowed.size();i++){
            mp[{allowed[i][0], allowed[i][1]}].push_back(allowed[i][2]);
        }

        return ans(prev,0,cur,mp,dp);

    }
};