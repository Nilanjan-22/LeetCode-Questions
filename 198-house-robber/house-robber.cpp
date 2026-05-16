class Solution {
public:
    int solve(int cur, vector<int>&nums, vector<int>& dp){
        if(cur>=nums.size())return 0;
        if(dp[cur]!=-1)return dp[cur];

        int money=0;
        //skip
        money=solve(cur+1,nums,dp);
        //take
        money=max(money, nums[cur]+solve(cur+2,nums,dp));

        return dp[cur]=money;

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};