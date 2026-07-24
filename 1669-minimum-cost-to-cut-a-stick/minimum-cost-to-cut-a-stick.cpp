class Solution {
public:
    long long solve(int st, int en, vector<int>& cuts, vector<vector<long long>>& dp){
        if(en<=st+1)return 0;
        if(dp[st][en]!=-1)return dp[st][en];

        long long minCost=INT_MAX;

        for(int i=st+1;i<en;i++){
            minCost = min(minCost , cuts[en]-cuts[st] +solve(st,i,cuts,dp)+solve(i,en,cuts,dp));
        }
        return dp[st][en]=minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int s=cuts.size()-1;

        vector<vector<long long>> dp(s+1,vector<long long>(s+1,-1));
        return solve(0,s,cuts,dp);
    }
};