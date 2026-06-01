class Solution {
public:
    int solve(int i, int k, vector<int>& arr,vector<int>& dp){
        if(i>=arr.size())return 0;
        if(dp[i]!=-1)return dp[i];

        int maxi=-1;
        int maxValue=0;
        for(int j=i;j<min(i+k,(int)arr.size());j++){
            maxi=max(maxi,arr[j]);
            maxValue=max(maxValue, maxi*(j+1-i)+solve(j+1,k,arr,dp));
        }
        return dp[i]=maxValue;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int maxi=-1;
            int maxValue=0;
            for(int j=i;j<min(i+k,(int)arr.size());j++){
                maxi=max(maxi,arr[j]);
                maxValue=max(maxValue, maxi*(j+1-i)+solve(j+1,k,arr,dp));
            }
            dp[i]=maxValue;
        }

        return dp[0];
        
    }
};