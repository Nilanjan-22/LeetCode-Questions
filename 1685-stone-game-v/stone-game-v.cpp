class Solution {
public:
    int solve(int i, int j, vector<int>& pref, vector<vector<int>>& dp){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int maxi=0;
        for(int it=i;it<j-1;it++){
            if(pref[it+1]-pref[i] <= pref[j]-pref[it+1])maxi=max(maxi , pref[it+1]-pref[i] + solve(i,it+1,pref,dp));
            if(pref[it+1]-pref[i] >= pref[j]-pref[it+1])maxi=max(maxi , pref[j]-pref[it+1] + solve(it+1,j,pref,dp));
        }
        return dp[i][j]=maxi;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+stoneValue[i-1];
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,pref,dp);
    }
};