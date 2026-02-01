// class Solution {
// public:
//     vector<vector<vector<int>>> dp;
//     int n;
//     int ans(int i, int turn , int skip,vector<int>& nums){
//         if(i>=n-1)return 0;
//         if(dp[i][turn][skip]!=-1)return dp[i][turn][skip];

//         int res=0;
//         if(turn==1){
//             if(nums[i+1]>nums[i])res=max(res,1+ans(i+1,0,skip,nums));
//         }
//         else {
//             if(nums[i+1]<nums[i])res=max(res,1+ans(i+1,1,skip,nums));
//         }

//         if(!skip && i+2<n){
//             if(turn==1){
//                 if(nums[i+2]>nums[i])res=max(res,1+ans(i+2,0,1,nums));
//             }
//             else{
//                 if(nums[i+2]<nums[i])res=max(res,1+ans(1+2,1,1,nums));
//             }
//         }

//         return dp[i][turn][skip]=res;
//     }
//     int longestAlternating(vector<int>& nums) {
//         n=nums.size();
//         dp.resize(n+1,vector<vector<int>>(2,vector<int>(2,-1)));
//         int res=1;
//         for(int i=0;i<n;i++){
//             res=max(res,max(1+ans(i,0,0,nums),1+ans(i,1,0,nums)));
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<int> arr;
    int n;
    int memo[100005][2][2];

    int solve(int idx, int isUp, int skipped) {
        if (idx >= n - 1) return 0;
        if (memo[idx][isUp][skipped] != -1) return memo[idx][isUp][skipped];

        int res = 0;

        // 1. Regular Move (to idx+1)
        if (isUp) {
            if (arr[idx+1] > arr[idx]) res = max(res, 1 + solve(idx + 1, 0, skipped));
        } else {
            if (arr[idx+1] < arr[idx]) res = max(res, 1 + solve(idx + 1, 1, skipped));
        }

        // 2. Skip Move (to idx+2) - Only if skipped == 0
        if (!skipped && idx + 2 < n) {
            if (isUp) {
                if (arr[idx+2] > arr[idx]) res = max(res, 1 + solve(idx + 2, 0, 1));
            } else {
                if (arr[idx+2] < arr[idx]) res = max(res, 1 + solve(idx + 2, 1, 1));
            }
        }

        return memo[idx][isUp][skipped] = res;
    }

    int longestAlternating(vector<int>& nums) {
        auto nexoraviml = nums;
        arr = nums;
        n = nums.size();
        if (n == 0) return 0;
        
        // Initialize memo table with -1
        for(int i=0; i<n; i++)
            for(int j=0; j<2; j++)
                for(int k=0; k<2; k++) memo[i][j][k] = -1;

        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            maxLen = max({maxLen, 1 + solve(i, 1, 0), 1 + solve(i, 0, 0)});
        }
        return maxLen;
    }
};