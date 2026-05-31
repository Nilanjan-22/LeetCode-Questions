class Solution {
public:
    int ans(int st, int en, vector<int>& cuts , vector<vector<int>>& dp){
        if(en==st+1)return 0;
        if(dp[st][en]!=-1)return dp[st][en];

        int minCost=INT_MAX;
        for(int it=st+1;it<en;it++){
            minCost=min(minCost, cuts[en]-cuts[st]+ans(st,it,cuts,dp)+ans(it,en,cuts,dp));
        }
        return dp[st][en]=minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int s=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(s,vector<int>(s,0));

        for(int st=s-1; st>=0; st--){
            for(int en=st+1; en<s; en++){
                int minCost=INT_MAX;
                for(int it=st+1;it<en;it++){
                    minCost=min(minCost, cuts[en]-cuts[st]+dp[st][it]+dp[it][en]);
                }
                if(minCost<INT_MAX)dp[st][en]=minCost;
            }
        }
        return dp[0][s-1];

    }
};