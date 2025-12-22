class Solution {
public:
    int ans(int cur, int prev, vector<string>& strs,vector<vector<int>>& dp){
        if(cur==strs[0].size())return 0;
        if(dp[cur][prev+1]!=-1)return dp[cur][prev+1];

        if(prev==-1){
            return dp[cur][prev+1]= min(1+ans(cur+1,prev,strs,dp), ans(cur+1,cur,strs,dp));
        }

        bool allsorted=true;
        for(int i=0;i<strs.size();i++){
            if(strs[i][prev]>strs[i][cur]){
                allsorted=false;
                break;
            }
        }

        if(allsorted){
            return dp[cur][prev+1]= min(1+ans(cur+1,prev,strs,dp), ans(cur+1,cur,strs,dp));
        }

        return dp[cur][prev+1]= 1+ans(cur+1,prev,strs,dp);
    }
    int minDeletionSize(vector<string>& strs) {
        int r=strs.size(),c=strs[0].size();
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));

        return ans(0,-1,strs,dp);
    }
};