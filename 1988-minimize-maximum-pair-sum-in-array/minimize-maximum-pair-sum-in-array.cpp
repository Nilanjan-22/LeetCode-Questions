class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int lo=0,hi=nums.size()-1;
        int ans=-1;
        while(lo<hi){
            ans=max(ans,nums[lo]+nums[hi]);
            lo++;
            hi--;
        }
        return ans;
    }
};