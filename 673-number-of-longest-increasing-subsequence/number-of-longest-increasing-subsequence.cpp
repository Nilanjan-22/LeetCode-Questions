class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> dp(n,{1,1});

        int maxLen=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[i].first==1+dp[j].first)dp[i].second+=dp[j].second;
                    else if(dp[i].first<1+dp[j].first){
                        dp[i].first=1+dp[j].first;
                        dp[i].second=dp[j].second;
                    }
                }
            }
            maxLen=max(dp[i].first,maxLen);
        }

        int numberOfLIS=0;
        for(int i=0;i<n;i++){
            if(dp[i].first==maxLen)numberOfLIS+=dp[i].second;
        }

        return numberOfLIS;
    }
};