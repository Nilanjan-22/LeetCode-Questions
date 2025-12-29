class Solution {
public:
    unordered_map <string, bool> dp;
    bool ans(string bottom , map<pair<char,char> , vector<char>>& mp , string cur , int i){
        if(bottom.size()==1)return true;

        string key= bottom + "_" + to_string(i) + "_" + cur;

        if(dp.find(key)!=dp.end())return dp[key];

        if(i==bottom.size()-1){
            return dp[key] = ans(cur,mp,"",0);
        }

        if(mp.find({bottom[i], bottom[i+1]})==mp.end()) return dp[key]=false;

        vector<char> cases=mp[{bottom[i], bottom[i+1]}];

        for(auto it: cases){
            cur.push_back(it);
            if(ans(bottom,mp,cur,i+1))return dp[key]=true;
            cur.pop_back();
        }
        return dp[key]=false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<pair<char,char> , vector<char>> mp;
        for(int i=0;i<allowed.size();i++){
            mp[{allowed[i][0],allowed[i][1]}].push_back(allowed[i][2]);
        }

        return ans(bottom, mp, "", 0);
    }
};