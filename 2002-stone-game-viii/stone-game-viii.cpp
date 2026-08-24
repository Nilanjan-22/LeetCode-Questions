class Solution {
public:
    int solve(int i, vector<int>&pref, vector<int>& dp){
        if(i==pref.size()-2){
            return pref[i+1];
        }
        if(dp[i]!=INT_MIN)return dp[i];
        int sum=INT_MIN;
        //take
        sum=max(sum,pref[i+1]-solve(i+1,pref,dp));
        //nottake
        sum=max(sum,solve(i+1,pref,dp));

        return dp[i]=sum;
    }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+stones[i-1];
        }
        vector<int> dp(n,INT_MIN);
        return solve(1,pref,dp);
    }
};