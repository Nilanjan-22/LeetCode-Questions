class Solution {
public:
    int ans(int i, int j, vector<int>& nums,vector<vector<int>>& dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int max_coins=INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int coins = nums[i-1]*nums[ind]*nums[j+1] + ans(i,ind-1,nums,dp) + ans(ind+1,j,nums,dp);
            max_coins=max(max_coins,coins);
        }
        return dp[i][j] = max_coins;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-2;i>=1;i--){
            for(int j=i; j<=n-2 ; j++){
                int max_coins=INT_MIN;
                for(int ind=i;ind<=j;ind++){
                    int coins = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1]+ dp[ind+1][j];
                    max_coins=max(max_coins,coins);
                }
                dp[i][j] = max_coins;
            }
        }
        return dp[1][n-2];
    }
};