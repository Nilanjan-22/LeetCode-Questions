class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,(long long)nums[i]);
            maxi=max(maxi,(long long)nums[i]);
        }
        return (maxi-mini)*(long long)k;
    }
};