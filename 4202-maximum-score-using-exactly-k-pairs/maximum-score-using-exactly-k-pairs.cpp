// class Solution {
// public:
//     // map<vector<int>,long long> dp;
//     int n,m;
//     long long ans(int i, int j, int k,vector<int>& n1 , vector<int>& n2, map<vector<int>,long long>& dp){
//         if(k==0)return 0;
//         if(i>=n || j>=m)return -1e18;

//         if(dp.find({i,j,k})!=dp.end())return dp[{i,j,k}];
//         // long long res=-1e18;
//         //pick both
//         long long pb= (long long)n1[i]*(long long)n2[j] + ans(i+1,j+1,k-1,n1,n2,dp);
//         //skip j
//         long long pi=ans(i,j+1,k,n1,n2,dp);
//         //skip i
//         long long pj=ans(i+1,j,k,n1,n2,dp);

//         return dp[{i,j,k}]=max(pj,max(pb,pi));
//     }
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//         // n1=nums1;
//         // n2=nums2;
//         n=nums1.size();
//         m=nums2.size();
//         map<vector<int>,long long> dp;
//         // dp.resize(n,vector<vector<long long>>(m,vector<long long>(k+1,-4e18)));
//         return ans(0,0,k,nums1,nums2,dp);

//     }   
// };

class Solution {
public:
    const long long NEG = -4e18;
    long long dp[101][101][101];

    long long maxScore(vector<int>& nums1,
                       vector<int>& nums2,
                       int k) {

        int n = nums1.size();
        int m = nums2.size();

        // initialize DP with NEG
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                for (int t = 0; t <= k; t++)
                    dp[i][j][t] = NEG;

        // base case
        dp[0][0][0] = 0;

        // fill DP table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int t = 0; t <= k; t++) {

                    if (i > 0)
                        dp[i][j][t] =
                            max(dp[i][j][t], dp[i-1][j][t]);

                    if (j > 0)
                        dp[i][j][t] =
                            max(dp[i][j][t], dp[i][j-1][t]);

                    if (i > 0 && j > 0 && t > 0 &&
                        dp[i-1][j-1][t-1] != NEG) {

                        dp[i][j][t] = max(
                            dp[i][j][t],
                            dp[i-1][j-1][t-1]
                            + 1LL * nums1[i-1] * nums2[j-1]
                        );
                    }
                }
            }
        }

        return dp[n][m][k];
    }
};