class Solution {
public:
    int solve(int i, int j,vector<int>& nums, vector<vector<int>>& dp){ 
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxCoins=0;
        for(int it=i;it<=j;it++){
            maxCoins=max(maxCoins, nums[i-1]*nums[it]*nums[j+1] + solve(i,it-1,nums,dp)+solve(it+1,j,nums,dp));
        }
        return dp[i][j]=maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> numCopy;
        numCopy.push_back(1);
        for(auto it: nums){
            numCopy.push_back(it);
        }
        numCopy.push_back(1);
        int n=numCopy.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(1,n-2,numCopy,dp);
    }
};