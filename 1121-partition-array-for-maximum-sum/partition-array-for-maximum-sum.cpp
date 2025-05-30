class Solution {
public:
    int ans(int i, int k, vector<int>& arr,vector<int>& dp){
        if(i>=arr.size())return 0;
        if(dp[i]!=-1)return dp[i];

        int maxsum=0;
        int maxi=0;
        for(int j=i; j<i+k && j<arr.size(); j++){
            maxi=max(maxi,arr[j]);
            int sum=maxi*(j-i+1)+ ans(j+1,k,arr,dp);
            maxsum=max(maxsum,sum);
        }
        return dp[i] = maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int maxi=0;
            int maxsum=0;
            for(int j=i; j<i+k && j<arr.size(); j++){
                maxi=max(maxi,arr[j]);
                int sum=maxi*(j-i+1)+ dp[j+1];
                maxsum=max(maxsum,sum);
            }
            dp[i] = maxsum;
        }
        return dp[0];
    }
};