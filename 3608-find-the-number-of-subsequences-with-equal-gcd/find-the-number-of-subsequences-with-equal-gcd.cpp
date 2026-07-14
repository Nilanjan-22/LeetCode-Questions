class Solution {
public:
    int mod=1e9+7;
    long long solve(int i, int g1, int g2, vector<int>& nums, vector<vector<vector<long long>>>& dp){
        if(i>=nums.size())return (g1==g2 && g1!=0) ? 1 : 0;

        if(dp[i][g1][g2]!=-1)return dp[i][g1][g2];
        long long ways=0;
        //put it in g1
        if(g1==0){
            ways+=solve(i+1,nums[i],g2,nums,dp);
        }
        else{
            ways+=solve(i+1,gcd(g1,nums[i]),g2,nums,dp);
        }
        ways%=mod;
        //put in g2
        if(g2==0){
            ways+=solve(i+1,g1,nums[i],nums,dp);
        }
        else{
            ways+=solve(i+1,g1,gcd(nums[i],g2),nums,dp);
        }
        ways%=mod;
        //skip
        ways+=solve(i+1,g1,g2,nums,dp);
        ways%=mod;

        return dp[i][g1][g2]=ways;

    }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(201,vector<long long>(201,-1)));
        return solve(0,0,0,nums,dp);
    }
};