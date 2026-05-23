class Solution {
public:
    int solve(int i, int tk, vector<int>&nums, vector<vector<int>>& dp){
        if(i>=nums.size())return 0;
        if(dp[i][tk]!=-1)return dp[i][tk];

        int longest=0;
        if(tk==nums.size() || nums[tk]<nums[i]){
            longest=max(longest,1+solve(i+1,i,nums,dp));
        }
        longest=max(longest, solve(i+1,tk,nums,dp));

        return dp[i][tk]=longest;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,n,nums,dp);
    }
};