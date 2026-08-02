class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long val = ((long long)nums[i] * (long long)nums[j])/pow(gcd(nums[i],nums[j]),2);
                ans=max(ans,val);
            }
        }
        return ans;
    }
};