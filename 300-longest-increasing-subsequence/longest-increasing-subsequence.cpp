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

    int LISUsingBS(vector<int>& nums){
        vector<int> list;
        for(int i=0;i<nums.size();i++){
            if(list.size()==0 || list.back()<nums[i]){
                list.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(list.begin(),list.end(),nums[i]);
                int ind = it-list.begin();
                list[ind]=nums[i];
            }
        }
        return list.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        return LISUsingBS(nums);
    }
};