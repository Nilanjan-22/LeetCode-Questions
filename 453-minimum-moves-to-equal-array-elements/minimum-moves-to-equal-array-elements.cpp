class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int mini=INT_MAX;
        for(auto it: nums){
            mini=min(mini,it);
        }
        for(int i=0;i<nums.size();i++){
            ans+=nums[i]-mini;
        }
        return ans;
    }
};