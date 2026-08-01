class Solution {
public:
    int p1Score (int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j)return 0;
        if(dp[i][j]!=INT_MIN)return dp[i][j];

        int takeFirst = nums[i] - p1Score(i+1,j,nums,dp);
        int takeLast = nums[j] - p1Score(i,j-1,nums,dp);
        return dp[i][j] = max(takeFirst, takeLast);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        return p1Score(0,n-1,nums,dp)>=0;
    }
};