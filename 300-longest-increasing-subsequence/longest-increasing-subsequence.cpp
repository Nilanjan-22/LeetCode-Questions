class Solution {
public:
    int LIS(int cur, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(cur==nums.size())return 0;
        if(dp[cur][prev]!=-1)return dp[cur][prev];

        int maxLen=0;
        if(prev==0 || nums[prev-1]<nums[cur]){
            maxLen = max(maxLen, 1+ LIS(cur+1,cur+1,nums,dp));
        }
        maxLen=max(maxLen,LIS(cur+1,prev,nums,dp));

        return dp[cur][prev]=maxLen;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return LIS(0,0,nums,dp);
    }
};