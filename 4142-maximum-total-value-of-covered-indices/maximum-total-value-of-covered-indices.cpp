class Solution {
public:
    long long solve(int ind, int tokenInPrev, vector<int>& nums, string& s, vector<vector<long long>>& dp){
        if(ind>=nums.size())return 0;
        if(dp[ind][tokenInPrev]!=-1)return dp[ind][tokenInPrev];

        long long maxVal=0;
        if(s[ind]=='0') return dp[ind][tokenInPrev] = solve(ind+1,0,nums,s,dp);

        //take cur
        maxVal= nums[ind]+solve(ind+1,1,nums,s,dp);
        if(tokenInPrev==0){
            maxVal=max(maxVal, nums[ind-1] + solve(ind+1,0,nums,s,dp));
        }

        return dp[ind][tokenInPrev]=maxVal;

    }
    long long maxTotal(vector<int>& nums, string s) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return solve(0,1,nums,s,dp);
    }
};