class Solution {
public:
    int solve(int i, int sum,int target, vector<int>& nums, map<pair<int,int>,int>&dp){
        if(i==nums.size()){
            if(sum==target)return 1;
            else return 0;
        }

        if(dp.find({i,sum})!=dp.end())return dp[{i,sum}];

        int ways=0;
        //take +
        ways+=solve(i+1,sum+nums[i],target,nums,dp);

        //take -
        ways+=solve(i+1,sum-nums[i],target,nums,dp);

        return dp[{i,sum}]=ways;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int> dp;

        return solve(0,0,target,nums,dp);
    }
};