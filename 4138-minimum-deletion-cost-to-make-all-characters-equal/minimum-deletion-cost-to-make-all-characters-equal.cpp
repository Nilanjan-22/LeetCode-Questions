class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char,long long> mp;
        long long total=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end())mp[s[i]]=cost[i];
            else mp[s[i]]+=cost[i];
            total+=cost[i];
        }

        long long maxi=LLONG_MIN;

        for(auto it: mp){
            maxi=max(maxi,it.second);
        }
        return total-maxi;

    }
};