class Solution {
public:
    vector<vector<int>> dp;
    int ans(int i1,int i2, vector<int>& nums1, vector<int>&nums2){
        if(i1>=nums1.size() || i2>=nums2.size())return -1e9;

        if(dp[i1][i2]!=INT_MIN)return dp[i1][i2];
        int take= nums1[i1]*nums2[i2] + ans(i1+1,i2+1,nums1,nums2);
        int nt1=ans(i1+1,i2,nums1,nums2);
        int nt2=ans(i1,i2+1,nums1,nums2);

        return dp[i1][i2]=max(nums1[i1]*nums2[i2],max(take,max(nt1,nt2)));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(501,vector<int>(501,INT_MIN));
        return ans(0,0,nums1,nums2);
    }
};