class Solution {
public:
    int solve(int cur, int robbedFirst, vector<int>&nums, vector<vector<int>>& dp){
        if(cur>=nums.size())return 0;
        if(dp[cur][robbedFirst]!=-1)return dp[cur][robbedFirst];
        int money=0;
        //take
        if(robbedFirst!=1 || cur!=nums.size()-1){
            if(cur==0){
                money=nums[cur]+ solve(cur+2,1,nums,dp);
            }
            else{
                money=nums[cur]+ solve(cur+2,robbedFirst,nums,dp);
            }
        }

        //skip
        money=max(money,solve(cur+1,robbedFirst,nums,dp));

        return dp[cur][robbedFirst]=money;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,0,nums,dp);
    }
};